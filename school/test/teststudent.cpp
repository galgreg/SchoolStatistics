#include "teststudent.h"
#include "student.h"

void TestStudent::testCreateStudent_data() {
    QTest::addColumn<Student>("student");
    QTest::addColumn<bool>("hasDefaultID");
    QTest::addColumn<QString>("expectedFullName");
    QTest::addColumn<Gender>("expectedGender");
    QTest::addColumn<int>("expectedNumberOfGrades");
    QTest::addColumn<double>("expectedGradesAverage");

    Student student_1, student_2("Johny", "English", MALE);
    QTest::addRow("Student without personal data") << student_1 << true << "" << UNKNOWN << 0 << 0.0;
    QTest::addRow("Student with personal data") << student_2 << false << "Johny English" << MALE << 0 << 0.0;
}

void TestStudent::testCreateStudent() {
    QFETCH(Student, student);
    QFETCH(bool, hasDefaultID);
    QFETCH(QString, expectedFullName);
    QFETCH(Gender, expectedGender);
    QFETCH(int, expectedNumberOfGrades);
    QFETCH(double, expectedGradesAverage);

    QCOMPARE(student.getID() == 0, hasDefaultID);
    QCOMPARE(student.getFullName(), expectedFullName);
    QCOMPARE(student.getGender(), expectedGender);

    checkGrades(student, expectedNumberOfGrades, expectedGradesAverage);
}

void TestStudent::testAddGrades() {
    Student student("Maria", "Nowak", FEMALE);
    student.addGrade(5.0);
    student.addGrade(4.5);
    student.addGrade(4.0);

    const int expectedGradesCount = 3;
    const double expectedGradesAverage = 4.5;
    checkGrades(student, expectedGradesCount, expectedGradesAverage);
}

void TestStudent::testRemoveGrades() {
    Student student("Jack", "Black", MALE);
    student.addGrade(3.0);
    student.addGrade(3.5);
    student.addGrade(4.0);
    student.removeGrade(0);

    const int expectedGradesCount = 2;
    const double expectedGradesAverage = 3.75;
    checkGrades(student, expectedGradesCount, expectedGradesAverage);
}

void TestStudent::checkGrades(
        const Student &student,
        int expectedGradesCount,
        double expectedGradesAverage) {
    auto studentGrades = student.getGrades();
    const int actualGradesCount = studentGrades.second - studentGrades.first;

    QCOMPARE(actualGradesCount, expectedGradesCount);
    QCOMPARE(student.getGradesAverage(), expectedGradesAverage);
}
