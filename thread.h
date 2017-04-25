#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include "receivefromappmain.h"

class Thread:public QThread
{
public:
    Thread();
    void run();

};

#endif // THREAD_H
