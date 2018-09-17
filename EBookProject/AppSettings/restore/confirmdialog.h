#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H
#include<QDialog>
#include<QPaintEvent>
#include<QPainter>
#include"drawconfimdialog.h"
#include<QMouseEvent>


class confirmDialog : public QDialog
{
public:
    confirmDialog(QWidget *parent);
    ~confirmDialog();

private:
    drawConfimDialog *drawconfirmdialog;
    void init();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // CONFIRMDIALOG_H
