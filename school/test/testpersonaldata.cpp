#include "testpersonaldata.h"
#include "gender.h"
#include "personaldata.h"

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

    PersonalData personalData(
                expectedFirstName, expectedLastName, expectedGender);
    const std::string actualFirstName = personalData.getFirstName();
    const std::string actualLastName = personalData.getLastName();
    const Gender actualGender = personalData.getGender();
    QCOMPARE(actualFirstName, expectedFirstName);
    QCOMPARE(actualLastName, expectedLastName);
    QCOMPARE(actualGender, expectedGender);
}
