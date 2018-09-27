#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include<QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawbrightness.h"
#include<QList>
#include"utils/redefineqrect.h"
#include"myutils.h"
#include"syssettings.h"

class Brightness : public QMainWindow
{
    Q_OBJECT
public:
    explicit Brightness(QWidget *parent = 0);
    ~Brightness();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    void init();
    void initView();
    void initConnections();
     void refreshLightUI(int x,int y,QRect lightrect);

    StatusBar *statusbar;
    DrawBrightness *drawbrightness;
    QList<myQRect*> *rectlist;
    myQRect* myqrect;
    int lightvalue;
    MyUtils *myutils;
    QRect lightrect;
    int targetwidgetIndex;
    SysSettings *syssettings;


signals:

public slots:
};

#endif // BRIGHTNESS_H
