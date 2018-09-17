#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include"utils/redefineqrect.h"
#include<QList>
#include<QPainter>
#include<statusbar.h>
#include"statusbar_global.h"
#include"drawdateandtime.h"

class DateAndTime : public QMainWindow
{
    Q_OBJECT
public:
    explicit DateAndTime(QWidget *parent = 0);
   ~DateAndTime();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void initView();
    void init();
    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    StatusBar *statusbar;
    DrawDateAndTime *drawdateandtime;

signals:

public slots:
};

#endif // DATEANDTIME_H
