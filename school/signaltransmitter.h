#ifndef SIGNALTRANSMITTER_H
#define SIGNALTRANSMITTER_H

#include "studentdataaction.h"
#include <QObject>

class SignalTransmitter : public QObject
{
    Q_OBJECT
public:
    explicit SignalTransmitter(QObject *parent = nullptr);

signals:
    void transactionCommitted(StudentDataAction);

public slots:
    void transmitSignal(StudentDataAction action);
};

#endif // SIGNALTRANSMITTER_H
