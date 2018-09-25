#include "dateandtime.h"
#include"application.h"
#include"rfile.h"
#include<QApplication>


const int DATE_X[] = {60,500,270};
const int DATE_Y[] = {48,48,130};
const int DATE_W[] = {48,48,60};
const int DATE_HE[] ={48,48,30};


extern int items_xywh[8][4];
extern int item_text_xywh[8][4];
extern int item_icon_xywh[8][4];


QString item_text_text[] = {QObject::tr("Date"),QObject::tr("Hour")};

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
    int x= event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = true;
        this->repaint();
    }

    if(x>items_xywh[0][0]&&x<items_xywh[0][0]+items_xywh[0][2]&&y>items_xywh[0][1]&&y<items_xywh[0][1]+items_xywh[0][3]){
        settimedialog->show();
    }

    if(x>items_xywh[1][0]&&x<items_xywh[1][0]+items_xywh[1][2]&&y>items_xywh[1][1]&&y<items_xywh[1][1]+items_xywh[1][3]){
        settimedialog->show();
    }

}


void DateAndTime::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);
    QLineF line(0,100,600,100);
    painter->drawLine(line);

    drawdateandtime->drawBackIcon(painter,rectlist->at(DATEANDTIME_BACKICON));
    drawdateandtime->drawHomeIcon(painter,rectlist->at(DATEANDTIME_HOMEICON));
    drawdateandtime->drawTitle(painter,rectlist->at(DATEANDTIME_TITLE),"Date");
    drawdateandtime->drawDateAndTimeItems(painter,systemitemlist,mydatemodel);





}

void DateAndTime::mouseReleaseEvent(QMouseEvent *event)
{
    switch (targetwidgetIndex) {
    case DATEANDTIME_BACKICON:
        this->close();
        break;
    case DATEANDTIME_HOMEICON:
        this->close();
        qApp->exit(0);
        break;
    case DATEANDTIME_TITLE:
        break;
    default:
        break;
    }

    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = false;
        targetwidgetIndex = -1;
        this->repaint();
    }

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
    settimedialog = new SetTimeDialog(this);
}

void DateAndTime::init()
{
    initView();

    statusbar = new StatusBar(this);
    drawdateandtime = new DrawDateAndTime;
    mydatemodel = new dateModel;

    mydatemodel->setTimezone(tr("China"));
    mydatemodel->setAutotime(true);
    QString systemtime="15:30 25/9";
    QStringList list = systemtime.split(" ");
    mydatemodel->setDate(list.at(0));
    mydatemodel->setTimehour(list.at(1));

    systemitemlist = new QList<SystemItems*>;

    for(int i=0;i<2;i++){
        item = new SystemItems;
        item->itemrect.setX(items_xywh[i][0]);
        item->itemrect.setY(items_xywh[i][1]);
        item->itemrect.setWidth(items_xywh[i][2]);
        item->itemrect.setHeight(items_xywh[i][3]);

        item->itemtextrect.setX(item_text_xywh[i][0]);
        item->itemtextrect.setY(item_text_xywh[i][1]);
        item->itemtextrect.setWidth(item_text_xywh[i][2]);
        item->itemtextrect.setHeight(item_text_xywh[i][3]);

        item->setItem_text_text(item_text_text[i]);

        item->itemiconrect.setX(item_icon_xywh[i][0]);
        item->itemiconrect.setY(item_icon_xywh[i][1]);
        item->itemiconrect.setWidth(item_icon_xywh[i][2]+5);
        item->itemiconrect.setHeight(item_icon_xywh[i][3]);
        //        item->item_icon_path = item_icon_paths[i];
        item->ispressed = false;
        systemitemlist->append(item);

    }


}
