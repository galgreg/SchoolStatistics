#include "testexecutioncounter.h"

TestExecutionCounter::TestExecutionCounter(
        unsigned &passed, unsigned &failed) :
            mPassed(passed), mFailed(failed) {

}

void TestExecutionCounter::incrementPassCounter() {
    ++mPassed;
}

void TestExecutionCounter::incrementFailCounter() {
    ++mFailed;
}

