#ifndef TESTEXECUTIONCOUNTER_H
#define TESTEXECUTIONCOUNTER_H

class TestExecutionCounter
{
protected:
    TestExecutionCounter(unsigned &passed, unsigned &failed) noexcept;
    void incrementPassCounter() noexcept;
    void incrementFailCounter() noexcept;
private:
    unsigned &mPassed;
    unsigned &mFailed;
};

#endif // TESTEXECUTIONCOUNTER_H
