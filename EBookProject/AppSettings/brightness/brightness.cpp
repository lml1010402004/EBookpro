#include "brightness.h"
#include"application.h"

Brightness::Brightness(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();
}

Brightness::~Brightness()
{

}

void Brightness::mousePressEvent(QMouseEvent *event)
{
  this->close();
}

void Brightness::paintEvent(QPaintEvent *event)
{

}

void Brightness::mouseMoveEvent(QMouseEvent *event)
{

}

void Brightness::mouseReleaseEvent(QMouseEvent *event)
{

}

void Brightness::init()
{

    initView();

}

void Brightness::initView()
{

}

void Brightness::initConnections()
{

}
