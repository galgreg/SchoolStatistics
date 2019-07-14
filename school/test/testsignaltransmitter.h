#ifndef TESTSIGNALTRANSMITTER_H
#define TESTSIGNALTRANSMITTER_H

#include "testexecutioncounter.h"
#include <QtTest>
#include "signaltransmitter.h"

class TestSignalTransmitter : public QObject, public TestExecutionCounter
{
    Q_OBJECT

public:
    TestSignalTransmitter(unsigned &passed, unsigned &failed);
private slots:
    void init();
    void cleanup();
    void testTransmitSignal_data();
    void testTransmitSignal();
private:
    std::unique_ptr<SignalTransmitter> mSignalTransmitter;
};

#endif // TESTSIGNALTRANSMITTER_H
