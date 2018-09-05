#-------------------------------------------------
#
# Project created by QtCreator 2018-09-05T09:42:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Launcher
TEMPLATE = app


INCLUDEPATH +=$$PWD main
include(main/main.pri)

INCLUDEPATH+=$$PWD DataBase
include(DataBase/DataBase.pri)

INCLUDEPATH+=$$PWD HomePage
include(HomePage/HomePage.pri)

INCLUDEPATH+=$$PWD BookShelf
include(BookShelf/BookShelf.pri)

INCLUDEPATH+=$$PWD ThirdApp
include(ThirdApp/ThirdApp.pri)

INCLUDEPATH+=$$PWD Setting
include(Setting/Setting.pri)

INCLUDEPATH+=$$PWD PullDownWindow
include(PullDownWindow/PullDownWindow.pri)
