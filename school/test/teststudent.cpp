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
    Student actualStudent(
            expectedID,
            std::make_unique<PersonalDataMock>(expectedPersonalData),
            std::make_unique<GradesMock>(expectedGrades));

    checkObjectState(
            actualStudent,
            expectedID,
            expectedPersonalData,
            expectedGrades);
}

void TestStudent::testChangeStateBySetters() {
    const unsigned expectedID_BeforeSet = 1;
    const IPersonalData& expectedPersonalData_BeforeSet = PersonalDataMock();
    const IGrades& expectedGrades_BeforeSet = GradesMock();

    Student actualStudent(
            expectedID_BeforeSet,
            std::make_unique<PersonalDataMock>(expectedPersonalData_BeforeSet),
            std::make_unique<GradesMock>(expectedGrades_BeforeSet));

    checkObjectState(
            actualStudent,
            expectedID_BeforeSet,
            expectedPersonalData_BeforeSet,
            expectedGrades_BeforeSet);

    const unsigned expectedID_AfterSet = expectedID_BeforeSet;
    const IPersonalData& expectedPersonalData_AfterSet = PersonalDataMock();
    const IGrades& expectedGrades_AfterSet = GradesMock();

    QCOMPARE(expectedID_BeforeSet, expectedID_AfterSet);

    actualStudent.setPersonalData(
            std::make_unique<PersonalDataMock>(expectedPersonalData_AfterSet));
    actualStudent.setGrades(
            std::make_unique<GradesMock>(expectedGrades_AfterSet));

    checkObjectState(
            actualStudent,
            expectedID_AfterSet,
            expectedPersonalData_AfterSet,
            expectedGrades_AfterSet);
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
