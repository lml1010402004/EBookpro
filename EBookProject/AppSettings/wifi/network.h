#ifndef NETWORK_H
#define NETWORK_H

#include <QMainWindow>
#include"drawnetwork.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include"utils/redefineqrect.h"
#include<QList>


class Network : public QMainWindow
{
    Q_OBJECT
public:
    explicit Network(QWidget *parent = 0);
    ~Network();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    void init();
    void initView();
    DrawNetwork *drawnetwork;
    StatusBar *statusbar;

    QList<myQRect*> *rectlist;
    myQRect *myqrect;


signals:

public slots:
};

#endif // NETWORK_H
