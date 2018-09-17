#ifndef USBTRANSFER_H
#define USBTRANSFER_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPainter>
#include<utils/redefineqrect.h>
#include"statusbar.h"
#include"statusbar_global.h"
#include"utils/redefineqrect.h"
#include"drawusbtransfer.h"
#include"usbservice.h"


class UsbTransfer : public QMainWindow
{
    Q_OBJECT
public:
    explicit UsbTransfer(QWidget *parent = 0);
    ~UsbTransfer();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void init();
    void initView();
    StatusBar *statusbar;
    DrawUsbtransfer *drawusbtransfer;
    UsbService *usbservice;



    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    int targetwidgetiIndex ;



signals:

public slots:
};

#endif // USBTRANSFER_H
