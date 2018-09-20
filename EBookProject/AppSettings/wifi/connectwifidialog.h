#ifndef CONNECTWIFIDIALOG_H
#define CONNECTWIFIDIALOG_H

#include <QDialog>
#include<QPainter>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QLineEdit>

class ConnectWifiDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectWifiDialog(QWidget *parent = 0);
    ~ConnectWifiDialog();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
 QLineEdit *mylineedit;
    void init();
    void initView();
    void initConnections();


signals:

public slots:
};

#endif // CONNECTWIFIDIALOG_H
