
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QWindow>
#include <QQmlContext>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QQuickItem>
#include <QObject>
#include <QQmlContext>
#include <QQuickView>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QtWidgets/QWidget>

#include "audio.h"
#include "hmieventcontroller.h"
#include"sendtoappmain.h"
#include "receivefromappmain.h"
#include "thread.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

   // QWidget::setWindowIcon("qrc:/imagebackgroud/LG.ico");
    QQuickView view;
    //view.setIcon (QIcon("qrc:/imagebackgroud/LG.ico"));
    SendToAppMain sendToAppMain;
    HMIEventController hMIEventController;

    view.rootContext()->setContextProperty("hMIEventController",&hMIEventController);
    view.setSource(QUrl("qrc:/main.qml"));
 // ket noi gui di

    QObject::connect(&hMIEventController, SIGNAL(playMusic(QString)), &sendToAppMain, SLOT(writeSharedMemory(QString)));
    QObject::connect(&hMIEventController, SIGNAL(stopMusic(QString)), &sendToAppMain, SLOT(writeSharedMemory(QString)));
    QObject::connect(&hMIEventController, SIGNAL(nextMusic(QString)), &sendToAppMain, SLOT(writeSharedMemory(QString)));
    QObject::connect(&hMIEventController, SIGNAL(addMusic(QString)), &sendToAppMain, SLOT(writeSharedMemory(QString)));
    QObject::connect(&hMIEventController, SIGNAL(pauseMusic(QString)), &sendToAppMain, SLOT(writeSharedMemory(QString)));
    QObject::connect(&hMIEventController, SIGNAL(climate(QString)), &sendToAppMain, SLOT(writeSharedMemory(QString)));

  // ket noi gui ve voi HMI controller

    ReceiveFromAppMain receiveFromAppMain;
    QObject::connect(&receiveFromAppMain,SIGNAL(musicIsPlayed(QString)),&hMIEventController,SLOT(AppMainEvent(QString)));
    QObject::connect(&receiveFromAppMain,SIGNAL(musicIsStopped(QString)),&hMIEventController,SLOT(AppMainEvent(QString)));
    QObject::connect(&receiveFromAppMain,SIGNAL(musicIsNexted(QString)),&hMIEventController,SLOT(AppMainEvent(QString)));
    QObject::connect(&receiveFromAppMain,SIGNAL(musicIsAdded(QString)),&hMIEventController,SLOT(AppMainEvent(QString)));
    QObject::connect(&receiveFromAppMain,SIGNAL(musicIsPaused(QString)),&hMIEventController,SLOT(AppMainEvent(QString)));
    QObject::connect(&receiveFromAppMain,SIGNAL(climateRunning(QString)),&hMIEventController,SLOT(AppMainEvent(QString)));




    QObject::connect(&receiveFromAppMain,QThread::finished,&hMIEventController,QObject::deleteLater);
    receiveFromAppMain.start();
    return app.exec();
}
