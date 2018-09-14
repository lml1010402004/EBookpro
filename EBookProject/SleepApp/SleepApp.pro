#-------------------------------------------------
#
# Project created by QtCreator 2018-09-05T09:57:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SleepApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    syssettings.h

RESOURCES += \
    mypics.qrc



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../PROJECTS/SleepScreen/libs/release/ -lSysSettings
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../PROJECTS/SleepScreen/libs/debug/ -lSysSettings
else:unix: LIBS += -L$$PWD/../../../../PROJECTS/SleepScreen/libs/ -lSysSettings

INCLUDEPATH += $$PWD/../../../../PROJECTS/SleepScreen/libs
DEPENDPATH += $$PWD/../../../../PROJECTS/SleepScreen/libs
