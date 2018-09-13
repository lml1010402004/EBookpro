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
    QList<QRect> *rectlist;
    QRect rect;
    DrawThirdApplication *mydrawapplication;
    int targetwidgetindex;
    StatusBar *statusbar;


signals:

public slots:
};

#endif // THIRDAPPLICATIONS_H
