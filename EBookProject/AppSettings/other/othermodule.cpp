#include "othermodule.h"
#include"application.h"
#include"rfile.h"

const int OTHERMODULE_X[] = {60,500,280};
const int OTHERMODULE_Y[] = {48,48,130};
const int OTHERMODULE_w[] ={48,48,80};
const int OTHERMODULE_HE[] = {48,48,24};

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
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);

    drawothermodule->drawBackIcon(painter,rectlist->at(OTHER_BACKICON));
    drawothermodule->drawHomeIcon(painter,rectlist->at(OTHER_HOMEICON));

    QLineF line(0,100,600,100);
    painter->drawLine(line);
    drawothermodule->drawTitle(painter,rectlist->at(OTHER_TITLE),tr("Other"));




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
  initView();
}

void OtherModule::initView()
{
    drawothermodule = new DrawOtherModule;
    statusbar = new StatusBar(this);
    rectlist = new QList<myQRect*>;

    for(int i=0;i<3;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(OTHERMODULE_X[i]);
        myqrect->rect.setY(OTHERMODULE_Y[i]);
        myqrect->rect.setWidth(OTHERMODULE_w[i]);
        myqrect->rect.setHeight(OTHERMODULE_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(OTHER_INDEX,myqrect,i);
        rectlist->append(myqrect);

    }

}
