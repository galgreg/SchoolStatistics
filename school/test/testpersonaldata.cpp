#include "testpersonaldata.h"

TestPersonalData::TestPersonalData(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestPersonalData::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestPersonalData::testGetters() {
    const std::string expectedFirstName = "Jan", expectedLastName = "Kowalski";
    const Gender expectedGender = MALE;

    PersonalData actualPersonalData(
            expectedFirstName, expectedLastName, expectedGender);
    testPersonalDataState(
            actualPersonalData,
            expectedFirstName,
            expectedLastName,
            expectedGender);
}

void TestPersonalData::testSetters() {
    const std::string expectedFirstName_Init = "Jan";
    const std::string expectedLastName_Init = "Kowalski";
    const Gender expectedGender_Init = MALE;

    PersonalData actualPersonalData(
            expectedFirstName_Init,
            expectedLastName_Init,
            expectedGender_Init);
    testPersonalDataState(
            actualPersonalData,
            expectedFirstName_Init,
            expectedLastName_Init,
            expectedGender_Init);

    const std::string expectedFirstName_Set = "Maria";
    const std::string expectedLastName_Set = "Nowak";
    const Gender expectedGender_Set = FEMALE;

    actualPersonalData.setFirstName(expectedFirstName_Set);
    actualPersonalData.setLastName(expectedLastName_Set);
    actualPersonalData.setGender(expectedGender_Set);

    testPersonalDataState(
            actualPersonalData,
            expectedFirstName_Set,
            expectedLastName_Set,
            expectedGender_Set);
}

void TestPersonalData::testPersonalDataState(
        const PersonalData &actualPersonalData,
        const std::string &expectedFirstName,
        const std::string &expectedLastName,
        Gender expectedGender) {
    QCOMPARE(actualPersonalData.getFirstName(), expectedFirstName);
    QCOMPARE(actualPersonalData.getLastName(), expectedLastName);
    QCOMPARE(actualPersonalData.getGender(), expectedGender);
}
