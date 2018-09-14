#include "othermodule.h"
#include"application.h"

OtherModule::OtherModule(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}

OtherModule::~OtherModule()
{

}

void OtherModule::paintEvent(QPaintEvent *event)
{

}

void OtherModule::mouseReleaseEvent(QMouseEvent *event)
{
    this->close();

}

void OtherModule::mouseMoveEvent(QMouseEvent *event)
{

}

void OtherModule::init()
{

}
