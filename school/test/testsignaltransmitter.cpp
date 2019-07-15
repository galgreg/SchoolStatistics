#include "testsignaltransmitter.h"
#include <QSignalSpy>

TestSignalTransmitter::TestSignalTransmitter(
        unsigned &passed,
        unsigned &failed) : TestExecutionCounter(passed, failed) {
}

void TestSignalTransmitter::init() {
    mSignalTransmitter.reset(new SignalTransmitter);
}

void TestSignalTransmitter::cleanup() {
    if (QTest::currentTestFailed()) {
        incrementFailCounter();
    } else {
        incrementPassCounter();
    }
}

void TestSignalTransmitter::testTransmitSignal_data() {
    QTest::addColumn<StudentDataAction>("actionToTransmit");

    QTest::newRow("transmit_add_student") << ADD_STUDENT;
    QTest::newRow("transmit_edit_student") << EDIT_STUDENT;
    QTest::newRow("transmit_delete_student") << DELETE_STUDENT;
}

void TestSignalTransmitter::testTransmitSignal() {
    QFETCH(StudentDataAction, actionToTransmit);
    QSignalSpy signalSpy(
            mSignalTransmitter.get(),
            &SignalTransmitter::transactionCommitted);
    mSignalTransmitter->transmitSignal(actionToTransmit);
    QCOMPARE(signalSpy.count(), 1);

    auto signalArguments = signalSpy.takeFirst();
    StudentDataAction expectedTransmittedAction = actionToTransmit;
    StudentDataAction actualTransmittedAction =
            signalArguments.at(0).value<StudentDataAction>();
    QCOMPARE(actualTransmittedAction, expectedTransmittedAction);
}
