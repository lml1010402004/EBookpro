#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T15:03:24
#
#-------------------------------------------------

QT       += widgets

TARGET = StatusBar
TEMPLATE = lib

DEFINES += STATUSBAR_LIBRARY

SOURCES += statusbar.cpp \
    pulldownwindow.cpp \
    r.cpp

HEADERS += statusbar.h\
        statusbar_global.h \
    pulldownwindow.h \
    redefineqrect.h \
    r.h \
    syssettings.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


RESOURCES += \
    pic.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lSysSettings
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lSysSettings
else:unix: LIBS += -L$$PWD/libs/ -lSysSettings

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs
