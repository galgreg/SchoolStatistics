#include "teststudentfactory.h"
#include "gender.h"
#include "studentfactory.h"
#include <memory>

TestStudentFactory::TestStudentFactory(unsigned &passed, unsigned &failed) :
    TestExecutionCounter(passed, failed) {

}

void TestStudentFactory::test_createStudent() {
    unsigned expectedID = 10;
    std::string expectedFirstName = "Jan";
    std::string expectedLastName = "Kowalski";
    Gender expectedGender = MALE;
    std::initializer_list<double> expectedGrades = {3.5, 4.5, 5.0};

    std::unique_ptr<IPersonalData> expectedPersonalData(
            new PersonalData(
                    expectedFirstName,
                    expectedLastName,
                    expectedGender));
    std::unique_ptr<IGrades> expectedGradesObject(new Grades(3, expectedGrades));
    std::unique_ptr<IStudent> expectedStudent(
            new Student(
                    expectedID,
                    *expectedPersonalData,
                    *expectedGradesObject));

    std::unique_ptr<IStudent> actualStudent(StudentFactory::create(
            expectedID,
            expectedFirstName,
            expectedLastName,
            expectedGender,
            expectedGrades));
    QCOMPARE(*actualStudent, *expectedStudent);
}

void TestStudentFactory::test_copyStudent() {
    unsigned expectedID = 10;
    std::string expectedFirstName = "Jan";
    std::string expectedLastName = "Kowalski";
    Gender expectedGender = MALE;
    std::initializer_list<double> expectedGrades = {3.5, 4.5, 5.0};

    std::unique_ptr<IPersonalData> expectedPersonalData(
            new PersonalData(
                    expectedFirstName,
                    expectedLastName,
                    expectedGender));
    std::unique_ptr<IGrades> expectedGradesObject(new Grades(3, expectedGrades));
    std::unique_ptr<IStudent> expectedStudent(
            new Student(
                    expectedID,
                    *expectedPersonalData,
                    *expectedGradesObject));

    std::unique_ptr<IStudent> actualStudent(
            StudentFactory::copy(*expectedStudent));
    QCOMPARE(*actualStudent, *expectedStudent);
}

void TestStudentFactory::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}