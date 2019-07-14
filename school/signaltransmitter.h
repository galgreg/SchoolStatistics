#ifndef SIGNALTRANSMITTER_H
#define SIGNALTRANSMITTER_H

#include "dialogaction.h"
#include <QObject>

class SignalTransmitter : public QObject
{
    Q_OBJECT
public:
    explicit SignalTransmitter(QObject *parent = nullptr);

signals:
    void transactionCommitted(DialogAction);

public slots:
    void transmitSignal(DialogAction action);
};

#endif // SIGNALTRANSMITTER_H
