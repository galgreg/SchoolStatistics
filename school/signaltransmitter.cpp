#include "signaltransmitter.h"

SignalTransmitter::SignalTransmitter() : QObject(nullptr) {

}

void SignalTransmitter::transmitSignal(StudentDataAction action) {
    emit transactionCommitted(action);
}
