#include "teststudent.h"
#include "gradesmock.h"
#include "igrades.h"
#include "ipersonaldata.h"
#include "personaldatamock.h"
#include "student.h"

TestStudent::TestStudent(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestStudent::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestStudent::testState_DefaultInitialized() {
    const unsigned expectedID = 1;
    IPersonalData* expectedPersonalData = nullptr;
    IGrades *expectedGrades = nullptr;

    Student actualStudent(expectedID);

    QCOMPARE(actualStudent.getID(), expectedID);
    QCOMPARE(actualStudent.getPersonalData(), expectedPersonalData);
    QCOMPARE(actualStudent.getGrades(), expectedGrades);
}

void TestStudent::testState_DataInitialized() {
    const unsigned expectedID = 1;
    IPersonalData* expectedPersonalData = new PersonalDataMock;
    IGrades *expectedGrades = new GradesMock;

    Student actualStudent(expectedID, expectedPersonalData, expectedGrades);

    QCOMPARE(actualStudent.getID(), expectedID);
    QCOMPARE(actualStudent.getPersonalData(), expectedPersonalData);
    QCOMPARE(actualStudent.getGrades(), expectedGrades);
}
