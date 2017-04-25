
TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    receivefromappmain.cpp \
    sendtoappmain.cpp \
    hmieventcontroller.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    imagebackgroud/background.jpg \
    imageaudio/audioplayer.png \
    imageaudio/cross-16.png \
    imageaudio/cross-32.png \
    imageaudio/media-mute-16.png \
    imageaudio/media-mute-32.png \
    imageaudio/media-mute-off-16.png \
    imageaudio/media-mute-off-32.png \
    imageaudio/media-pause-16.png \
    imageaudio/media-pause-32.png \
    imageaudio/media-play-16.png \
    imageaudio/media-play-32.png \
    imageaudio/media-seek-backward-16.png \
    imageaudio/media-seek-backward-32.png \
    imageaudio/media-seek-forward-16.png \
    imageaudio/media-seek-forward-32.png \
    imageaudio/media-stop-16.png \
    imageaudio/media-stop-32.png \
    imageaudio/media-volume-1-16.png \
    imageaudio/media-volume-1-32.png \
    imageaudio/media-volume-2-16.png \
    imageaudio/media-volume-2-32.png \
    imageaudio/media-volume-3-16.png \
    imageaudio/media-volume-3-32.png \
    imageaudio/minus-16.png \
    imageaudio/minus-32.png \
    imageaudio/next-16.png \
    imageaudio/next-32.png \
    imageaudio/plus-16.png \
    imageaudio/plus-32.png \
    imageaudio/previous-16.png \
    imageaudio/previous-32.png \
    imagebackgroud/back.png \
    imagebackgroud/background.png \
    imagebackgroud/call.png \
    imagebackgroud/climate.png \
    imagebackgroud/contacts.png \
    imagebackgroud/music.png \
    imagebackgroud/phonebook.png \
    imagebackgroud/setting.png \
    imageaudio/audioplayer.ico \
    imageaudio/qt-logo.ico

HEADERS += \
    receivefromappmain.h \
    sendtoappmain.h \
    hmieventcontroller.h
