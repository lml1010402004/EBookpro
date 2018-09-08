#-------------------------------------------------
#
# Project created by QtCreator 2018-09-05T16:12:32
#
#-------------------------------------------------

QT       += core gui

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
