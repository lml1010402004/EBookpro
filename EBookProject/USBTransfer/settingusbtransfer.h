#ifndef SETTINGUSBTRANSFER_H
#define SETTINGUSBTRANSFER_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPaintEvent>
#include"drawViewfunctions/drawsettingusbtransfer.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include<QPainter>
#include"usbservice.h"
#include"database/database.h"
#include"syssettings.h"
#include<QRect>
#include"utils/commonutils.h"

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

class settingUSBTransfer : public QMainWindow
{
    Q_OBJECT
public:
    explicit settingUSBTransfer(QWidget *parent = 0);
    ~settingUSBTransfer();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void init();
    usbConnectedThread *usbconnectedthread;

private:

    drawSettingUsbTransfer *drawsettingusbtransfer;
    StatusBar *statubar;
    QPainter *painter;
    UsbService *usbservice;
     SysSettings *mysyssetting;
     QRect rect;
     commonUtils *mytils;
     bool isMountingStorageScard;




signals:
    void showPullDownSignal();
    void backToHomePageSignal();
    void updateTheBookDataSignal();



public slots:
    void backToHomePageSlot();
    void updateTimeAndBatteryValue(QString time,int battery);
    void updateStateOfUsb();


};

#endif // SETTINGUSBTRANSFER_H
