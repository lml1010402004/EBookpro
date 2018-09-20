#include "othermodule.h"
#include"application.h"
#include"rfile.h"
#include"commonutils.h"

const int OTHERMODULE_X[] = {60,500,280};
const int OTHERMODULE_Y[] = {48,48,130};
const int OTHERMODULE_w[] ={48,48,80};
const int OTHERMODULE_HE[] = {48,48,24};

extern int items_xywh[8][4];
extern int item_text_xywh[8][4];
extern int item_icon_xywh[8][4];
const QString item_text_text[] = {QObject::tr("Sleep"),QObject::tr("Device")};

OtherModule::OtherModule(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}

OtherModule::~OtherModule()
{
    for(int i=0;i<rectlist->size();i++){
        delete rectlist->at(i);
    }
    for(int j=0;j<systemitemlist->size();j++){
        delete systemitemlist->at(j);
    }
    delete statusbar,drawothermodule,myqrect,rectlist,systemitemlist;
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
    drawothermodule->drawOtherSettingItems(painter,systemitemlist);


}

void OtherModule::mouseReleaseEvent(QMouseEvent *event)
{

}

void OtherModule::mouseMoveEvent(QMouseEvent *event)
{

}

void OtherModule::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    targetWidgetIndex = commonUtils::getTargetIndexInSettingModule(x,y,systemitemlist);
    if(targetWidgetIndex>-1){
        systemitemlist->at(targetWidgetIndex)->ispressed= true;
        this->repaint();
    }
    switch (targetWidgetIndex) {
    case 0:
        if(settingsleeptime== NULL){
            settingsleeptime->show();
        }
        break;
    case 1:
        if(deviceinfo==NULL){
            deviceinfo->show();
        }
        break;
    default:
        break;
    }





}

void OtherModule::init()
{
    targetWidgetIndex =-1;
    settingsleeptime = new SettingSleepTime(this);
    deviceinfo = new DeviceInfo(this);

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
        item->itemiconrect.setWidth(item_icon_xywh[i][2]);
        item->itemiconrect.setHeight(item_icon_xywh[i][3]);
        //        item->item_icon_path = item_icon_paths[i];
        item->ispressed = false;
        systemitemlist->append(item);
    }

}
