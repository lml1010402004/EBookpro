#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "statusbar_global.h"
#include<QMainWindow>
#include<QPainter>
#include<QWidget>
#include<QRect>
#include<QString>
#include<QPaintEvent>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
#include<QFont>




class STATUSBARSHARED_EXPORT StatusBar:public QMainWindow
{
    Q_OBJECT

public:
    StatusBar(QWidget *widget);
    ~StatusBar();
    void drawSystemTime(QPainter *painter,QString time);
    void drawWifiStatus(QPainter *painter,bool flag);
    void drawBattery(QPainter *painter,int percentage);
    void drawPullDownRectangle(QPainter *painter);

    int getTheBatteryPercentage();
    QString getTheCurrentTime();







private:
    QRect rect;
    QFont font;

signals:
    void broadcastTimeAndBattery(QString time,int battery);

public slots:
     void startMyTimer();
     void updateTimeRightNowSlot();

};

#endif // STATUSBAR_H
