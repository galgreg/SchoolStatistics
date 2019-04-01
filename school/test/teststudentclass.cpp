#include "teststudentclass.h"
#include "studentclass.h"

TestStudentClass::TestStudentClass(
        unsigned &passed, unsigned &failed) :
    TestExecutionCounter(passed, failed) {
}

void TestStudentClass::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestStudentClass::testStateAfterInitialization() {
    const size_t expectedMaxCount = 20;
    const size_t expectedCount = 0;
    StudentClass actualClass(expectedMaxCount);
    QCOMPARE(actualClass.count(), expectedCount);
    QCOMPARE(actualClass.maxAllowedCount(), expectedMaxCount);
}

