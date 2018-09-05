#include "mainwindow.h"
#include<QPainter>
#include<QRect>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(800);
    this->setFixedWidth(600);
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    QRect rect;
    rect.setX(0);
    rect.setY(0);
    rect.setWidth(300);
    rect.setHeight(400);
    painter->drawText(rect,QString("hello world!!!"));

}
