#-------------------------------------------------
#
# Project created by QtCreator 2017-12-11T14:27:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MTPService
TEMPLATE = app


SOURCES += main.cpp\
        mydialog.cpp \
    sambaservice.cpp \
    wifiservice.cpp

HEADERS  += mydialog.h \
    wifiservice.h \
    sambaservice.h

FORMS    +=

RESOURCES += \
    pics.qrc
