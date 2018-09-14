#include "wallpaper.h"
#include"application.h"

WallPaper::WallPaper(QWidget *parent) : QMainWindow(parent)
{
   this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
   this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
   this->setFixedWidth(GLOBAL_FIXED_WIDTH);
   init();

}

WallPaper::~WallPaper()
{

}

void WallPaper::paintEvent(QPaintEvent *event)
{

}

void WallPaper::mousePressEvent(QMouseEvent *event)
{
    this->close();
}

void WallPaper::mouseMoveEvent(QMouseEvent *event)
{

}

void WallPaper::mouseReleaseEvent(QMouseEvent *event)
{

}

void WallPaper::init()
{

}

void WallPaper::initView()
{

}
