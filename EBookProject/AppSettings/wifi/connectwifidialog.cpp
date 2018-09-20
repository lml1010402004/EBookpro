#include "connectwifidialog.h"
#include<QHBoxLayout>
#include<QCursor>
#include<QApplication>


ConnectWifiDialog::ConnectWifiDialog(QWidget *parent) : QDialog(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setGeometry(QRect(100,150,400,300));
    QHBoxLayout *midlayout = new QHBoxLayout;
    mylineedit = new QLineEdit(this);
    midlayout->addWidget(mylineedit);
    midlayout->setGeometry(QRect(0,0,400,300));

    setLayout(midlayout);
    QCursor cursor(0);
    mylineedit->setCursor(cursor);
    init();
}

ConnectWifiDialog::~ConnectWifiDialog()
{

}

void ConnectWifiDialog::paintEvent(QPaintEvent *event)
{

}

void ConnectWifiDialog::mousePressEvent(QMouseEvent *event)
{
    this->close();

}

void ConnectWifiDialog::init()
{

}

void ConnectWifiDialog::initView()
{

}

void ConnectWifiDialog::initConnections()
{

}
