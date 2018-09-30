#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include<QPaintEvent>
#include<QPainter>
#include<QPixmap>
#include<QLineF>
#include<QFont>
#include<QRect>
#include"sambaservice.h"


class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QPainter *painter;
    QPixmap pixmap;
    QLineF line;
    QFont font;
    QRect rect;
    SambaService* samba;
    WifiService *wifi;

    void startMTPService();


    void init();

    void paintContent(QPainter *painter);

    void paintWifiStatus(QPainter *painter);
    void paintStartMTPService(QPainter *painter);

    bool flag;


};

#endif // MYDIALOG_H
