#include "dateandtime.h"
#include"application.h"

DateAndTime::DateAndTime(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}

void DateAndTime::mousePressEvent(QMouseEvent *event)
{

}

void DateAndTime::paintEvent(QPaintEvent *event)
{

}

void DateAndTime::mouseReleaseEvent(QMouseEvent *event)
{
  this->close();
}

void DateAndTime::init()
{


}
