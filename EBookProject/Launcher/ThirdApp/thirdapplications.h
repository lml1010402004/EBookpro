#ifndef THIRDAPPLICATIONS_H
#define THIRDAPPLICATIONS_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
#include"ThirdApp/thirdapplications.h"
#include"ThirdApp/drawthirdapplication.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include"Utils/redefineqrect.h"
#include"Application/pulldownwindow.h"

class ThirdApplications : public QMainWindow
{
    Q_OBJECT
public:
    explicit ThirdApplications(QWidget *parent = 0);
    ~ThirdApplications();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void init();
    void initView();

    void initAppItems();

    QList<QRect> *rectlist;
    myQRect *myhomerect;
    myQRect *apptext;
    DrawThirdApplication *mydrawapplication;
    int targetwidgetindex;
    StatusBar *statusbar;
    SystemItems *item;

    QList<SystemItems*> *systemitemlist;
     PulldownWindow *pulldownwindow;


signals:

public slots:
};

#endif // THIRDAPPLICATIONS_H
