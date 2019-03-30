#include "teststudentinfo.h"
#include "studentinfo.h"

TestStudentInfo::TestStudentInfo(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {

}

void TestStudentInfo::testCreate() {
    const unsigned expectedID = 10;
    const QString expectedFullName = "Henryk Walezy";
    const Gender expectedGender = MALE;

    StudentInfo info(expectedID, expectedFullName, expectedGender);
    QCOMPARE(info.hisID, expectedID);
    QCOMPARE(info.hisFullName, expectedFullName);
    QCOMPARE(info.hisGender, expectedGender);
}

void TestStudentInfo::cleanup() {
    if(QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}
