#include "teststudent.h"
#include "student.h"

TestStudent::TestStudent(unsigned &passed, unsigned &failed) :
        TestExecutionCounter(passed, failed) {

}

void TestStudent::testCreateStudent_data() {
    QTest::addColumn<Student>("student");
    QTest::addColumn<bool>("hasDefaultID");
    QTest::addColumn<QString>("expectedFullName");
    QTest::addColumn<Gender>("expectedGender");
    QTest::addColumn<int>("expectedNumberOfGrades");
    QTest::addColumn<double>("expectedGradesAverage");

    Student student_1, student_2("Jan", "Nowak", MALE);
    QTest::addRow("Default initialized student") << student_1 << true << "" << UNKNOWN << 0 << 0.0;
    QTest::addRow("Student initialized with data") << student_2 << false << "Jan Nowak" << MALE << 0 << 0.0;
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
    Student student("Maria", "Kowalska", FEMALE);
    student.addGrade(5.0);
    student.addGrade(4.5);
    student.addGrade(4.0);

    const int expectedGradesCount = 3;
    const double expectedGradesAverage = 4.5;
    checkGrades(student, expectedGradesCount, expectedGradesAverage);
}

void TestStudent::testRemoveGrades() {
    Student student("Janusz", "Polak", MALE);
    student.addGrade(3.0);
    student.addGrade(3.5);
    student.addGrade(4.0);

    const int gradesCountBeforeRemove = 3;
    const double gradesAverageBeforeRemove = 3.5;
    checkGrades(student, gradesCountBeforeRemove, gradesAverageBeforeRemove);

    student.removeGrade(0);

    const int gradesCountAfterRemove = 2;
    const double gradesAverageAfterRemove = 3.75;
    checkGrades(student, gradesCountAfterRemove, gradesAverageAfterRemove);
}

void TestStudent::testEditGrades() {
    Student student("Pioter", "Nosacz", MALE);
    student.addGrade(3.0);
    student.addGrade(3.0);
    student.addGrade(3.0);

    const int gradesCountBeforeEdit = 3;
    const double gradesAverageBeforeEdit = 3.0;
    checkGrades(student, gradesCountBeforeEdit, gradesAverageBeforeEdit);

    student.editGrade(0, 5.0);
    student.editGrade(2, 4.0);

    const int gradesCountAfterEdit = 3;
    const double gradesAverageAfterEdit = 4.0;
    checkGrades(student, gradesCountAfterEdit, gradesAverageAfterEdit);
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

void TestStudent::cleanup() {
    if(QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}
