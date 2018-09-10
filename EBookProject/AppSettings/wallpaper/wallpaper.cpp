#include "wallpaper.h"
#include"application/pulldownwindow.h"
#include"application/statusbar.h"
#include"application/statusbar_global.h"
#include"application.h"

const int backbuttonp[] = {60,60,48,48};
const int homebuttonp[] = {480,60,48,48};


Wallpaper::Wallpaper(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();
}

Wallpaper::~Wallpaper()
{

}

void Wallpaper::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(x>backbutton.rect.x()&&x<(backbutton.rect.x()+backbutton.rect.width())&&y>backbutton.rect.y()&&y<(backbutton.rect.y()
            +backbutton.rect.width())){
        backbutton.isPressed = true;
           this->close();
    }

    if(x>homebutton.rect.x()&&x<(homebutton.rect.x()+homebutton.rect.width())&&y>homebutton.rect.y()&&y<(homebutton.rect.y()
            +homebutton.rect.width())){
           this->close();
        homebutton.isPressed = true;
    }





}

void Wallpaper::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    drawwallpaper->drawBackIcon(painter,backbutton);
    drawwallpaper->drawHomeIcon(painter,homebutton);

    statusbar->drawBattery(painter,80);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);
//    statusbar->draw


}

void Wallpaper::mouseReleaseEvent(QMouseEvent *event)
{
    homebutton.isPressed = false;
    backbutton.isPressed = false;

}

void Wallpaper::mouseMoveEvent(QMouseEvent *event)
{

}

void Wallpaper::init()
{

    statusbar = new StatusBar(this);
    initView();

}

void Wallpaper::initView()
{

    drawwallpaper = new DrawWallpaper;
    backbutton.rect.setX(backbuttonp[0]);
    backbutton.rect.setY(backbuttonp[1]);
    backbutton.rect.setWidth(backbuttonp[2]);
    backbutton.rect.setHeight(backbuttonp[3]);
    backbutton.isPressed = false;

    homebutton.rect.setX(homebuttonp[0]);
    homebutton.rect.setY(homebuttonp[1]);
    homebutton.rect.setWidth(homebuttonp[2]);
    homebutton.rect.setHeight(homebuttonp[3]);
    homebutton.isPressed = false;

}
