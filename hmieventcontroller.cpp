#include "hmieventcontroller.h"
#include "audio.h"
#include "receivefromappmain.h"
#include <QDebug>


HMIEventController::HMIEventController()
{
}

HMIEventController::~HMIEventController()
{

}

void HMIEventController::HMIEvent(QString event )
{
    if (event=="play")
    {
        emit playMusic("play");
    }
    else if (event=="stop")
    {
        emit stopMusic("stop");
    }
   else if (event =="next")
    {
        emit nextMusic ("next");
    }
    else if (event =="add")
    {
        emit addMusic ("add");
    }
    else if (event=="pause")
    {
        emit pauseMusic ("pause");
    }
    else if (event=="climate")
    {
        emit climate ("climate");
    }
}

