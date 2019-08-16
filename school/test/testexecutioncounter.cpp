#include "testexecutioncounter.h"

TestExecutionCounter::TestExecutionCounter(
        unsigned &passed, unsigned &failed) noexcept :
            mPassed(passed), mFailed(failed) {

}

void TestExecutionCounter::incrementPassCounter() noexcept {
    ++mPassed;
}

void TestExecutionCounter::incrementFailCounter() noexcept {
    ++mFailed;
}

