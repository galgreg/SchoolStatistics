#include "teststudent.h"
#include "gradesmock.h"
#include "personaldatamock.h"

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
    const IPersonalData& expectedPersonalData = PersonalDataMock();
    const IGrades& expectedGrades = GradesMock();
    Student actualStudent(expectedID, expectedPersonalData, expectedGrades);

    checkObjectState(
            actualStudent,
            expectedID,
            expectedPersonalData,
            expectedGrades);
}

void TestStudent::testState_DataInitialized() {
    const unsigned expectedID = 1;
    std::unique_ptr<IPersonalData> expectedPersonalData(new PersonalDataMock);
    std::unique_ptr<IGrades> expectedGrades(new GradesMock);
    Student actualStudent(expectedID, *expectedPersonalData, *expectedGrades);

    checkObjectState(
            actualStudent,
            expectedID,
            *expectedPersonalData,
            *expectedGrades);
}

void TestStudent::testChangeStateBySetters() {
    const unsigned expectedID_BeforeSet = 1;
    std::unique_ptr<IPersonalData> expectedPersonalData_BeforeSet(new PersonalDataMock);
    std::unique_ptr<IGrades> expectedGrades_BeforeSet(new GradesMock);

    Student actualStudent(
            expectedID_BeforeSet,
            *expectedPersonalData_BeforeSet,
            *expectedGrades_BeforeSet);

    checkObjectState(
            actualStudent,
            expectedID_BeforeSet,
            *expectedPersonalData_BeforeSet,
            *expectedGrades_BeforeSet);

    const unsigned expectedID_AfterSet = expectedID_BeforeSet;
    std::unique_ptr<IPersonalData> expectedPersonalData_AfterSet(new PersonalDataMock);
    std::unique_ptr<IGrades> expectedGrades_AfterSet(new GradesMock);

    QCOMPARE(expectedID_BeforeSet, expectedID_AfterSet);
    QVERIFY(expectedPersonalData_BeforeSet != expectedPersonalData_AfterSet);
    QVERIFY(expectedGrades_BeforeSet != expectedGrades_AfterSet);

    actualStudent.setPersonalData(*expectedPersonalData_AfterSet);
    actualStudent.setGrades(*expectedGrades_AfterSet);

    checkObjectState(
            actualStudent,
            expectedID_AfterSet,
            *expectedPersonalData_AfterSet,
            *expectedGrades_AfterSet);
}

void TestStudent::checkObjectState(
        const Student &actualStudent,
        unsigned expectedID,
        const IPersonalData &expectedPersonalData,
        const IGrades &expectedGrades) {
    QCOMPARE(actualStudent.getID(), expectedID);
    QCOMPARE(actualStudent.getPersonalData(), expectedPersonalData);
    QCOMPARE(actualStudent.getGrades(), expectedGrades);
}
