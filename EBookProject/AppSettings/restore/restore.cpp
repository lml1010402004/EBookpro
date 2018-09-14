#include "restore.h"
#include"application.h"

Restore::Restore(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}

Restore::~Restore()
{

}

void Restore::paintEvent(QPaintEvent *event)
{

}

void Restore::mousePressEvent(QMouseEvent *event)
{
    this->close();

}

void Restore::mouseMoveEvent(QMouseEvent *event)
{

}

void Restore::mouseReleaseEvent(QMouseEvent *event)
{

}

void Restore::init()
{

}
