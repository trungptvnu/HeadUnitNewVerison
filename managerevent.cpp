#include "managerevent.h"

ManagerEvent::ManagerEvent()
{

}

void ManagerEvent::CheckEvent(QString event)
{
    if (event == "play")
    {
        AudioController audiocontroller;
        audiocontroller.play();
    }
    else
        qDebug() << "chua nhan duoc";
}
