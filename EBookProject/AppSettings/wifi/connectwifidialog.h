#ifndef CONNECTWIFIDIALOG_H
#define CONNECTWIFIDIALOG_H

#include <QDialog>
#include<QPainter>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QLineEdit>
#include"redefineqrect.h"
#include<QList>
#include"drawconnectwifidialog.h"

class ConnectWifiDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectWifiDialog(QWidget *parent = 0);
    ~ConnectWifiDialog();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QLineEdit *mylineedit;
    void init();
    void initView();
    void initConnections();
    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    int targetwidgetIndex;
    DrawConnectWifiDialog *drawconnectwifidialog;


signals:

public slots:
};

#endif // CONNECTWIFIDIALOG_H
