#ifndef RECEIVERESULT_H
#define RECEIVERESULT_H

#include <QObject>
#include <QSharedMemory>
#include <QThread>
#include <QTimer>
#include <QMutex>
#include <QWaitCondition>

class ReceiveFromAppMain :public QThread
{
    Q_OBJECT


public:
    ReceiveFromAppMain();
    ~ReceiveFromAppMain();
    void run() override;
    void readSharedMemory(QString server);

//comunication
signals:
    void musicIsPlayed(QString);
    void musicIsStopped (QString);
    void musicIsNexted (QString);
    void musicIsAdded(QString);
    void musicIsPaused(QString);
    void climateRunning(QString);

 private:


    QSharedMemory sharedMemory;
};

#endif // RECEIVERESULT_H
