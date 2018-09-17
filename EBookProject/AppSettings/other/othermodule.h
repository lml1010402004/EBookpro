#ifndef OTHERMODULE_H
#define OTHERMODULE_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawothermodule.h"
#include"utils/redefineqrect.h"


class OtherModule : public QMainWindow
{
    Q_OBJECT
public:
    explicit OtherModule(QWidget *parent = 0);
    ~OtherModule();
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void init();
    void initView();
    StatusBar *statusbar;
    DrawOtherModule *drawothermodule;
    QList<myQRect*> *rectlist;
    myQRect *myqrect;

    QList<SystemItems*> *systemitemlist;
    SystemItems *item;

signals:

public slots:
};

#endif // OTHERMODULE_H
