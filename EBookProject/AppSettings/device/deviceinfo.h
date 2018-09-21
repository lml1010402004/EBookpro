#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QMainWindow>
#include<QPainter>
#include<QMouseEvent>
#include<utils/redefineqrect.h>
#include"drawdeviceinfo.h"
#include"utils/redefineqrect.h"
#include<QList>
#include"statusbar.h"
#include"statusbar_global.h"

class DeviceInfo : public QMainWindow
{
    Q_OBJECT
public:
    explicit DeviceInfo(QWidget *parent = 0);
    ~DeviceInfo();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private :
    void init();
    void initView();
    DrawDeviceInfo *drawdeviceinfo;
    QList<myQRect*> *rectlist;
    myQRect *myrect;
    StatusBar *statusbar;

    int targetwidgetIndex;

signals:

public slots:
};

#endif // DEVICEINFO_H
