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
#include"wallpaper/wallpaper.h"


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
    PulldownWindow *pulldownwindow;
    DrawMainWindow *drawmainwindow;
    myQRect *myrect;


    int targetWidgetIndex;
    QList<SystemItems*> *systemitemlist;
    SystemItems *item;
    Wallpaper *wallpaper;



signals:

public slots:
};

#endif // MAINWINDOW_H
