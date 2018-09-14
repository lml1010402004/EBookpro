#include "network.h"
#include"application.h"

Network::Network(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();
}

Network::~Network()
{

}

void Network::mousePressEvent(QMouseEvent *event)
{

}

void Network::mouseMoveEvent(QMouseEvent *event)
{

}

void Network::mouseReleaseEvent(QMouseEvent *event)
{
this->close();
}

void Network::paintEvent(QPaintEvent *event)
{

}

void Network::init()
{

}

void Network::initView()
{

}
