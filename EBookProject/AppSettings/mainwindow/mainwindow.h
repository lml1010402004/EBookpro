#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
#include"application/pulldownwindow.h"
#include"application/statusbar.h"
#include"application/statusbar_global.h"
#include"drawmainwindow.h"
#include<QList>
#include<wallpaper/wallpaper.h>
#include<brightness/brightness.h>
#include<wifi/network.h>
#include<dateandtime/dateandtime.h>
#include"languageandkeyboard/languagekeyboard.h"
#include"restore/restore.h"
#include"other/othermodule.h"
#include"usbtransfer/usbtransfer.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void init();
    void initView();
    void initsettingsModules();

    StatusBar *statusbar;
    DrawMainWindow *drawmainwindow;
    myQRect *myrect;


    int targetWidgetIndex;
    QList<SystemItems*> *systemitemlist;
    SystemItems *item;


    WallPaper *wallpaper;
    Brightness *brightness;
    Network *wifinetwork;
    DateAndTime *dateandtime;
    LanguageKeyboard *languagekeyboard;
    Restore *restore;
    OtherModule *othermodule;
    UsbTransfer *usbtransfer;



signals:

public slots:
};

#endif // MAINWINDOW_H
