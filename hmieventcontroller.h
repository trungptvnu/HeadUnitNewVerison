#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QString>

#include <QDebug>
#include <QWidgetList>
#include <QThread>

class HMIEventController : public QObject
{
    Q_OBJECT

public:
    HMIEventController();
    virtual ~HMIEventController();
// Gui di
// ham nhan tin hieu click va phan loai event

   Q_INVOKABLE void HMIEvent(QString );

//tao signal gui di sau khi click
signals:
    void playMusic(const QString);
    void stopMusic(const QString);
    void nextMusic(const QString);
    void addMusic(const QString);
    void pauseMusic(const QString);
    void climate(const QString);


//nhan ve
    // tao signal hien thi len QML
    void played();
    void stopped();
    void nexted();
    void added();
    void paused();
    void climated ();

public slots:

   void AppMainEvent(QString event)
    {
       if (event=="played")
       {
        emit played();
        qDebug()<<"da ket noi";
       }
       else if (event=="stopped")
       {
        emit stopped();
        qDebug()<<"da ket noi";
       }
      else if (event=="nexted")
       {
        emit nexted();
        qDebug()<<"da ket noi";
       }
       else if (event=="added")
       {
           emit added ();
        qDebug()<<"da ket noi";
       }
       else if (event=="paused")
       {
           emit paused();
           qDebug()<< "da ket noi";
       }
       else if (event=="climated")
       {
           emit climated ();
       }
    }

};

#endif // RECEIVER_H
