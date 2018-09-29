#-------------------------------------------------
#
# Project created by QtCreator 2018-01-22T09:39:01
#
#-------------------------------------------------

QT       -= gui

TARGET = SysSettings
TEMPLATE = lib

DEFINES += SYSSETTINGS_LIBRARY

SOURCES += syssettings.cpp \
    lcd_backlight.cpp

HEADERS += syssettings.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
