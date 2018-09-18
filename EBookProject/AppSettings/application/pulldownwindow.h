#ifndef PULLDOWNWINDOW_H
#define PULLDOWNWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QList>
#include<QRect>
#include<QPainter>
#include"statusbar.h"
#include"statusbar_global.h"
#include<QProcess>
#include"redefineqrect.h"
#include"r.h"
#include"syssettings.h"

const QString wifi_unpress=":/pic/pic/wifi.png";
const QString wifi_press=":/pic/pic/wifi_pressed.png";
const QString setting_unpress=":/pic/pic/setting_unpress.png";
const QString setting_press=":/pic/pic/setting_pressed.png";
const QString search_unpress=":/pic/pic/search_unpress.png";
const QString search_press=":/pic/pic/search_pressed.png";

const QString minus_unpress=":/pic/pic/minus_uppress.png";
const QString minus_press=":/pic/pic/minus_pressed.png";
const QString plus_unpress=":/pic/pic/plus_unpress.png";
const QString plus_press=":/pic/pic/plus_pressed.png";

const QString closeIcon =":/pic/pic/pulldown_close.png";

class PulldownWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PulldownWindow(QWidget *parent = 0);
    ~PulldownWindow();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);


private:
    void drawCloseIcon(QPainter *painter,myQRect* rect);
    void drawShortcutArea(QPainter *painter,myQRect* rect);
    void drawGrayArea(QPainter *painter,int al,myQRect* rect);
    void drawShortcutIcons(QPainter *painter,myQRect* rect1,myQRect* rect2,myQRect* rect3);
    void drawLightshortcutandProgressBar(QPainter *painter,QString lightpath,int light_volume,myQRect* rect,QString floatpath);


    void drawLightPlus(QPainter *painter,myQRect* plusrect);
    void drawLightMinus(QPainter *painter,myQRect* minusrect);

    void drawProgressBarForLight(QPainter *painter,int value);

    int getTheLightValueFromXY(int pos_x,int pos_y,QRect rect);



private:
    void init();
    void initView();
    QList<myQRect*> *rectlist;
    myQRect* myrect;
    int targetwidgetindex;
    int getTheTargetWidget(int x,int y, QList<myQRect*> *rectlist);
    void refreshLightUI(int x,int y);

    StatusBar *statusbar;
    QProcess *myprocess;
    QRect lightrect;
    int lightvalue;
    bool lightarea;
    SysSettings *mysyssetting;

signals:

public slots:
};

#endif // PULLDOWNWINDOW_H
