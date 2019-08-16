#include "teststudentfactory.h"
#include "gender.h"
#include "grades.h"
#include "personaldata.h"
#include "studentfactory.h"
#include <memory>

TestStudentFactory::TestStudentFactory(unsigned &passed, unsigned &failed) :
    TestExecutionCounter(passed, failed) {

}

void TestStudentFactory::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestStudentFactory::test_createStudent() {
    unsigned expectedID = 10;
    QString expectedFirstName = "Jan";
    QString expectedLastName = "Kowalski";
    Gender expectedGender = MALE;
    QList<double> expectedGrades = {3.5, 4.5, 5.0};

    std::unique_ptr<IPersonalData> expectedPersonalData(
            new PersonalData(
                    expectedFirstName,
                    expectedLastName,
                    expectedGender));
    std::unique_ptr<IGrades> expectedGradesObject(new Grades(3, expectedGrades));
    std::unique_ptr<IStudent> expectedStudent(
            new Student(
                    expectedID,
                    std::move(expectedPersonalData),
                    std::move(expectedGradesObject)));

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
    QString expectedFirstName = "Jan";
    QString expectedLastName = "Kowalski";
    Gender expectedGender = MALE;
    QList<double> expectedGrades = {3.5, 4.5, 5.0};

    auto expectedPersonalData =
            std::make_unique<PersonalData>(
                    expectedFirstName,
                    expectedLastName,
                    expectedGender);
    auto expectedGradesObject =
            std::make_unique<Grades>(3, expectedGrades);
    auto expectedStudent =
            std::make_unique<Student>(
                    expectedID,
                    std::move(expectedPersonalData),
                    std::move(expectedGradesObject));

    auto actualStudent = StudentFactory::copy(*expectedStudent);
    QCOMPARE(*actualStudent, *expectedStudent);
}
