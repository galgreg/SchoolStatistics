#include "testgrades.h"

TestGrades::TestGrades(unsigned &passed, unsigned &failed) :
        TestExecutionCounter(passed, failed) {

}

void TestGrades::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

