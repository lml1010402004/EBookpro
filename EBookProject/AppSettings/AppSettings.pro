#-------------------------------------------------
#
# Project created by QtCreator 2018-09-05T16:12:32
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppSettings
TEMPLATE = app

INCLUDEPATH +=$$PWD main
include(main/main.pri)

INCLUDEPATH +=$$PWD brightness
include(brightness/brightness.pri)

INCLUDEPATH +=$$PWD dateandtime
include(dateandtime/dateandtime.pri)

INCLUDEPATH +=$$PWD languageandkeyboard
include(languageandkeyboard/languageandkeyboard.pri)

INCLUDEPATH +=$$PWD mainwindow
include(mainwindow/mainwindow.pri)

INCLUDEPATH +=$$PWD restore
include(restore/restore.pri)

INCLUDEPATH +=$$PWD usbtransfer
include(usbtransfer/usbtransfer.pri)

INCLUDEPATH +=$$PWD wallpaper
include(wallpaper/wallpaper.pri)

INCLUDEPATH +=$$PWD wifi
include(wifi/wifi.pri)

INCLUDEPATH +=$$PWD utils
include(utils/utils.pri)

INCLUDEPATH +=$$PWD application
include(application/application.pri)

INCLUDEPATH +=$$PWD dataitem
include(dataitem/dataitem.pri)

INCLUDEPATH +=$$PWD other
include(other/other.pri)




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lPinyinIM
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lPinyinIM
else:unix: LIBS += -L$$PWD/libs/ -lPinyinIM

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lStatusBar
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lStatusBar
else:unix: LIBS += -L$$PWD/libs/ -lStatusBar

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lSysSettings
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lSysSettings
else:unix: LIBS += -L$$PWD/libs/ -lSysSettings

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

RESOURCES += \
    mypic.qrc
