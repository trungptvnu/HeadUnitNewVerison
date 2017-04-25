#include "receivefromappmain.h"
#include "hmieventcontroller.h"
#include<QBuffer>
#include<QtCore/QDebug>
#include<QDataStream>
#include <Qtimer>
#include<QThread>

ReceiveFromAppMain::ReceiveFromAppMain()
{

}

ReceiveFromAppMain::~ReceiveFromAppMain()
{

}
void ReceiveFromAppMain::readSharedMemory(QString server)
{
    sharedMemory.setKey(server);
    if (!sharedMemory.attach())
    {
        return ;
    }
    QBuffer buffer;
    QDataStream in(&buffer);
    QString string;

    sharedMemory.lock();
    buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >>string;
    sharedMemory.unlock();

     if (string=="played")
     {

         emit musicIsPlayed("played");
         qDebug()   << "dang choi nhac";
     }
     else if (string=="stopped")
     {

         emit musicIsStopped("stopped");
         qDebug()   << "stop";
     }
    else if (string=="nexted")
     {
         emit musicIsNexted("nexted");
         qDebug()   << "next";
     }
     else if (string == "added")
     {
         emit musicIsAdded ("added");
         qDebug() <<"add";
     }
     else if (string =="paused")
     {
         emit musicIsPaused ("paused");
         qDebug()<<"pause";
     }
     else if (string=="runclimate")
     {
         emit climateRunning ("climated");
         qDebug()<<"cliamate";
     }
     buffer.close();
}
void ReceiveFromAppMain::run()
{
   while (true)
    {       
        this ->readSharedMemory("server7");
        // sleep(2);
        this ->readSharedMemory("server8");
        //sleep(2);
        this ->readSharedMemory("server9");
        // sleep(2);
        this ->readSharedMemory("server10");
        // sleep(2);
        this ->readSharedMemory("server11");
       // sleep(2);
       this ->readSharedMemory("server12");
        sleep(1);
   }
}



