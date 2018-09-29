#-------------------------------------------------
#
# Project created by QtCreator 2017-12-12T16:11:38
#
#-------------------------------------------------

QT += sql dbus
TARGET = PinyinIM
TEMPLATE = lib

DEFINES += PINYINIM_LIBRARY

SOURCES += pinyinim.cpp \
    keyboard.cpp

HEADERS += pinyinim.h\
    keyboard.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    pinyinim.qrc

FORMS +=
