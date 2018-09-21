#include "drawsettingsleep.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;


 int LISTVIEW_X[] = {70,530,80,80,100};
 int LISTVIEW_Y[] = {170,170,190,240,250};
 int LISTVIEW_ITEM_HEIGHT = 90;
const int LISTVIEW_ITEM_TEXT_WIDTH=120;


const QString TIMESGROUP[5] = {QObject::tr("1 min"),QObject::tr("3 mins"),QObject::tr("5 mins"),QObject::tr("15 mins"),QObject::tr("Never")};

drawSettingSleep::drawSettingSleep()
{

}

drawSettingSleep::~drawSettingSleep()
{

}

void drawSettingSleep::drawBackIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }

}

void drawSettingSleep::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }

}

void drawSettingSleep::drawTitle(QPainter *painter, myQRect *rect, QString title)
{
    painter->drawText(rect->rect,title);
}

void drawSettingSleep::drawSleepTimeListview(QPainter *painter, int targetindex)
{
    QRect myqrect;
    for(int i=0;i<5;i++){
        QLineF line(LISTVIEW_X[0],LISTVIEW_Y[0]+LISTVIEW_ITEM_HEIGHT*i,LISTVIEW_X[1],LISTVIEW_Y[1]+LISTVIEW_ITEM_HEIGHT*i);
        painter->drawLine(line);
        if(targetindex==i){
        QLineF line1(LISTVIEW_X[2],LISTVIEW_Y[2]+LISTVIEW_ITEM_HEIGHT*i,LISTVIEW_X[3],LISTVIEW_Y[3]+LISTVIEW_ITEM_HEIGHT*i);
        painter->drawLine(line1);
        }

        myqrect.setX(LISTVIEW_X[4]);
        myqrect.setY(LISTVIEW_Y[0]+LISTVIEW_ITEM_HEIGHT*i+20);
        myqrect.setWidth(LISTVIEW_ITEM_TEXT_WIDTH);
        myqrect.setHeight(LISTVIEW_ITEM_HEIGHT-40);
        painter->drawText(myqrect,TIMESGROUP[i]);
    }
    QLineF line(LISTVIEW_X[0],LISTVIEW_Y[0]+LISTVIEW_ITEM_HEIGHT*5,LISTVIEW_X[1],LISTVIEW_Y[1]+LISTVIEW_ITEM_HEIGHT*5);
    painter->drawLine(line);

}
