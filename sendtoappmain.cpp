#include <QBuffer>
#include "sendtoappmain.h"
#include <QtCore/QDebug>
#include<QObject>
#include <QDataStream>
#include "hmieventcontroller.h"


SendToAppMain::SendToAppMain()
{

}


void SendToAppMain::writeSharedMemory(QString event)
{
    if (event=="play")
    {
        sharedMemory.setKey ("server1");
    }
    else if (event=="stop")
    {
        sharedMemory.setKey ("server2");
    }
    else if (event=="next")
    {
        sharedMemory.setKey ("server3");
    }
    else if (event=="add")
    {
        sharedMemory.setKey ("server4");
    }
    else if (event =="pause")
    {
        sharedMemory.setKey ("server5");
    }
    else if (event =="climate")
    {
        sharedMemory.setKey ("server6");
    }
//    sharedMemory.setKey("server");
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << event;
    int size = buffer.size();

    if (!sharedMemory.create(size))
    {
        qDebug()<<"Unable to create shared memory segment.";
        return;
    }
    sharedMemory.lock();
    char *to = (char*)sharedMemory.data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(sharedMemory.size(), size));
    sharedMemory.unlock();
    buffer.close();
}
