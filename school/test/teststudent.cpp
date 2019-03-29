#include "teststudent.h"
#include "student.h"

void TestStudent::testCreateDefaultStudent() {
    Student studentToVerify;
    verifyStudentData(studentToVerify, 0, "", UNKNOWN, 0, 0.0);
}

void TestStudent::testCreateStudent() {
    Student studentToVerify("John", "Smith", MALE);
    verifyStudentData(studentToVerify, 0, "", UNKNOWN, 0, 0.0);
}

void TestStudent::verifyStudentData(
        const Student &student,
        unsigned expectedID,
        const QString &expectedFullName,
        Gender expectedGender,
        int expectedGradesNumber,
        double expectedGradesAverage) {
    QCOMPARE(student.getID(), expectedID);
    QCOMPARE(student.getFullName(), expectedFullName);
    QCOMPARE(student.getGender(), expectedGender);
    auto studentGrades = student.getGrades();
    int howManyGrades = studentGrades.second - studentGrades.first;
    QCOMPARE(howManyGrades, expectedGradesNumber);
    QCOMPARE(student.getGradesAverage(), expectedGradesAverage);
}
