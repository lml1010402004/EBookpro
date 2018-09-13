#include "thirdapplications.h"
#include"application.h"
#include"Utils/commonutils.h"



ThirdApplications::ThirdApplications(QWidget *parent) : QMainWindow(parent)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();
}

ThirdApplications::~ThirdApplications()
{
  delete statusbar,rectlist,mydrawapplication;
}

void ThirdApplications::init()
{
    initView();
    mydrawapplication = new DrawThirdApplication;
    targetwidgetindex = -1;
}

void ThirdApplications::initView()
{
    rectlist = new QList<QRect>;
    statusbar = new StatusBar(this);

}

void ThirdApplications::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);



}

void ThirdApplications::mousePressEvent(QMouseEvent *event)
{
//    targetwidgetindex = commonUtils::getTheTargetWidget(event->x(),event->y(),rectlist);
    this->repaint();
    this->close();
}

void ThirdApplications::mouseMoveEvent(QMouseEvent *event)
{

}

void ThirdApplications::mouseReleaseEvent(QMouseEvent *event)
{

    if(targetwidgetindex>-1){
        switch (targetwidgetindex) {
        case 0:

            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }

        this->repaint(rectlist->at(targetwidgetindex));
        targetwidgetindex = -1;

    }
}


