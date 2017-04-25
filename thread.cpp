#include "thread.h"

Thread::Thread()
{

}

void Thread::run()
{
    QTimer timer;
    ReceiveFromAppMain receiveFromAppMain;
    QObject::connect(&timer,QTimer::timeout, &receiveFromAppMain, ReceiveFromAppMain::readSharedMemory);
    timer.start(10);
    exec();
}
