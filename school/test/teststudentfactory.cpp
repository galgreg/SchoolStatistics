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
    size_t expectedGradesCount = 3;
    std::vector<double> expectedGrades = {3.5, 4.5, 5.0};

    std::unique_ptr<IStudent> actualStudent(StudentFactory::create(
            expectedID,
            expectedFirstName,
            expectedLastName,
            expectedGender,
            expectedGrades));
    const IPersonalData& actualPersonalData = actualStudent->getPersonalData();
    const IGrades& actualGrades = actualStudent->getGrades();

    unsigned actualID = actualStudent->getID();
    QCOMPARE(actualID, expectedID);

    std::string actualFirstName = actualPersonalData.getFirstName();
    QCOMPARE(actualFirstName, expectedFirstName);

    std::string actualLastName = actualPersonalData.getLastName();
    QCOMPARE(actualLastName, expectedLastName);

    Gender actualGender = actualPersonalData.getGender();
    QCOMPARE(actualGender, expectedGender);

    size_t actualGradesCount = actualGrades.count();
    QCOMPARE(actualGradesCount, expectedGradesCount);

    for (unsigned i = 0; i < actualGradesCount; ++i) {
        double expectedGrade = expectedGrades.at(i);
        double actualGrade = actualGrades.getGrade(i);
        QCOMPARE(actualGrade, expectedGrade);
    }
}

void TestStudentFactory::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}
