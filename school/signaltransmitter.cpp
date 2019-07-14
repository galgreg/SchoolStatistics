#include "signaltransmitter.h"

SignalTransmitter::SignalTransmitter(QObject *parent) : QObject(parent) {

}

void SignalTransmitter::transmitSignal(DialogAction action) {
    emit transactionCommitted(action);
}
