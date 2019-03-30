#ifndef TESTEXECUTIONCOUNTER_H
#define TESTEXECUTIONCOUNTER_H

class TestExecutionCounter
{
protected:
    TestExecutionCounter(unsigned &passed, unsigned &failed);
    void incrementPassCounter();
    void incrementFailCounter();
private:
    unsigned &mPassed;
    unsigned &mFailed;
};

#endif // TESTEXECUTIONCOUNTER_H
