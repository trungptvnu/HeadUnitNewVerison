#ifndef MANAGEREVENT_H
#define MANAGEREVENT_H

#include <QObject>
#include "receiver.h"
#include "audiocontroller.h"

class ManagerEvent
{
public:
    ManagerEvent();
    void CheckEvent(QString event);
};

#endif // MANAGEREVENT_H
