#ifndef SIGNALTRANSMITTER_H
#define SIGNALTRANSMITTER_H

#include <QObject>

class SignalTransmitter : public QObject
{
    Q_OBJECT
public:
    explicit SignalTransmitter(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SIGNALTRANSMITTER_H