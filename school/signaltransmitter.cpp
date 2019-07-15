#include "signaltransmitter.h"

SignalTransmitter::SignalTransmitter(QObject *parent) : QObject(parent) {

}

void SignalTransmitter::transmitSignal(StudentDataAction action) {
    emit transactionCommitted(action);
}
