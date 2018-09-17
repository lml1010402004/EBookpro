#include "dateandtime.h"
#include"application.h"
#include"rfile.h"

const int DATE_X[] = {60,500,270};
const int DATE_Y[] = {48,48,130};
const int DATE_W[] = {48,48,30};
const int DATE_HE[] ={48,48,30};

DateAndTime::DateAndTime(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}

DateAndTime::~DateAndTime()
{
    delete rectlist,myqrect;

}

void DateAndTime::mousePressEvent(QMouseEvent *event)
{

}

void DateAndTime::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);

    drawdateandtime->drawBackIcon(painter,rectlist->at(DATEANDTIME_BACKICON));
    drawdateandtime->drawHomeIcon(painter,rectlist->at(DATEANDTIME_HOMEICON));
    drawdateandtime->drawTitle(painter,rectlist->at(DATEANDTIME_TITLE),"Date");


}

void DateAndTime::mouseReleaseEvent(QMouseEvent *event)
{
    this->close();
}

void DateAndTime::initView()
{
    rectlist = new QList<myQRect*>;
    for(int i=0;i<3;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(DATE_X[i]);
        myqrect->rect.setY(DATE_Y[i]);
        myqrect->rect.setWidth(DATE_W[i]);
        myqrect->rect.setHeight(DATE_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(DATEANDTIME_INDEX,myqrect,i);
        rectlist->append(myqrect);
    }

}

void DateAndTime::init()
{
    initView();

    statusbar = new StatusBar(this);
    drawdateandtime = new DrawDateAndTime;

}
