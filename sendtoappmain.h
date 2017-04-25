#ifndef SENDTOSERVICE_H
#define SENDTOSERVICE_H

#include <QObject>
#include <QSharedMemory>
#include "hmieventcontroller.h"

class SendToAppMain: public QObject
{
    Q_OBJECT
public:
    SendToAppMain();

public slots:
    void writeSharedMemory(QString event);

private:
    QSharedMemory sharedMemory;

};

#endif // SENDTOSERVICE_H
