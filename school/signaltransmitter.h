#ifndef SIGNALTRANSMITTER_H
#define SIGNALTRANSMITTER_H

#include "studentdataaction.h"
#include <QObject>

class SignalTransmitter : public QObject
{
    Q_OBJECT
public:
    SignalTransmitter();

signals:
    void transactionCommitted(StudentDataAction);
    void requestFormAction(StudentDataAction);
    void showEditForm();

public slots:
    void transmitSignal(StudentDataAction action);
};

#endif // SIGNALTRANSMITTER_H
