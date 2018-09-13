#include "thirdapplications.h"
#include"application.h"
#include"Utils/commonutils.h"

const int HOME_XYWH[] ={500,48,48,48};
const int APP_TITLE_XYWH[]={260,110,80,60};
QString APPTEXT="Apps";


int items_xywh[4][4] = {
    {50,170,500,70},
    {50,240,500,70},
    {50,310,500,70},
    {50,380,500,70}
};

int item_text_xywh[4][4] = {
    {70,190,200,40},
    {70,260,200,40},
    {70,330,200,40},
    {70,400,200,40}
};

int item_icon_xywh[4][4] = {
    {480,180,50,50},
    {480,250,50,50},
    {480,320,50,50},
    {480,390,50,50}
};

const QString item_text_text[4] ={
    QObject::tr("Light"),QObject::tr("WallPaper"),QObject::tr("Network"),QObject::tr("USB Transfer")};



ThirdApplications::ThirdApplications(QWidget *parent) : QMainWindow(parent)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();
}

ThirdApplications::~ThirdApplications()
{
    delete statusbar,rectlist,mydrawapplication,myhomerect,apptext,item,systemitemlist;
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
    myhomerect = new myQRect;
    myhomerect->rect.setX(HOME_XYWH[0]);
    myhomerect->rect.setY(HOME_XYWH[1]);
    myhomerect->rect.setWidth(HOME_XYWH[2]);
    myhomerect->rect.setHeight(HOME_XYWH[3]);
    myhomerect->isPressed = false;

    apptext = new myQRect;
    apptext->rect.setX(APP_TITLE_XYWH[0]);
    apptext->rect.setY(APP_TITLE_XYWH[1]);
    apptext->rect.setWidth(APP_TITLE_XYWH[2]);
    apptext->rect.setHeight(APP_TITLE_XYWH[3]);
    apptext->isPressed = false;

    initAppItems();



}

void ThirdApplications::initAppItems()
{
    systemitemlist = new QList<SystemItems*>;
    for(int i=0;i<4;i++){
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
        item->itemiconrect.setWidth(item_icon_xywh[i][2]);
        item->itemiconrect.setHeight(item_icon_xywh[i][3]);
        //        item->item_icon_path = item_icon_paths[i];
        item->ispressed = false;
        systemitemlist->append(item);

    }

}

void ThirdApplications::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);
    mydrawapplication->drawHomeIcon(painter,myhomerect);
    QLineF line(0,100,600,100);
    painter->drawLine(line);
    mydrawapplication->drawAppsText(painter,APPTEXT,apptext);
    mydrawapplication->drawAppsItems(painter,systemitemlist);

}

void ThirdApplications::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(x>HOME_XYWH[0]&&x<HOME_XYWH[0]+HOME_XYWH[2]&&y>HOME_XYWH[1]&&y<HOME_XYWH[1]+HOME_XYWH[3]){
        myhomerect->isPressed = true;
        this->repaint();
    }

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


