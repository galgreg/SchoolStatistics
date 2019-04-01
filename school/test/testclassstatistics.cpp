#include "testclassstatistics.h"

TestClassStatistics::TestClassStatistics(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {
}

void TestClassStatistics::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}
