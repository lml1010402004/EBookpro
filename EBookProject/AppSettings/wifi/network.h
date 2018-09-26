#ifndef NETWORK_H
#define NETWORK_H

#include <QMainWindow>
#include"drawnetwork.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include"utils/redefineqrect.h"
#include<QList>
#include"wifiservice.h"
#include"connectwifidialog.h"
#include"wifiitem.h"
#include"application/syssettings.h"



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
    void initConnections();
    QList<wifiItem*>* getCurrentPageWifiList(QList<wifiItem*> *list,int currentPage,int totalPages);
    void clickWifiListat(int x,int y,QList<wifiItem*> *list);

    DrawNetwork *drawnetwork;
    StatusBar *statusbar;

    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    int targetwidgetIndex;
    QRect switch_button;
    bool wifi_flag;
    WifiService *mywifiservice;
    ConnectWifiDialog *connectwifidialog;
    SysSettings *mysyssetting;
    QString targetWifiMac;
    QList<wifiItem*> *wifilist;
    QList<wifiItem*> *currentpagewifilist;
    int wifiCurrentPage;
    int wifiTotalPages;
    bool first_come_in;
    QString wifi_mac;


signals:

public slots:
    void wifi_StatusChanged(QString wifistatus);
    void wifi_RefreshDone(QList<TWifi> wifi_Lists);
    void connectWifiSlot(QString password);
};

#endif // NETWORK_H
