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

#include<QThread>

class usbConnectedThread : public QThread{

    Q_OBJECT
public:
    usbConnectedThread(QString node);
    explicit usbConnectedThread(QObject *parent = 0);

protected:
    void run();

signals:
     void updateUsbConnectSignal();


};

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
    void initConnections();

    void insertDataToDatabase();
    StatusBar *statusbar;
    DrawUsbtransfer *drawusbtransfer;
    UsbService *usbservice;



    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    int targetwidgetiIndex ;
    usbConnectedThread *usbconnectedthread;



signals:

public slots:
    void updateStateOfUsb();
};

#endif // USBTRANSFER_H
