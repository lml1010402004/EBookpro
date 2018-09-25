#include "drawdateandtime.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;



DrawDateAndTime::DrawDateAndTime()
{

}

DrawDateAndTime::~DrawDateAndTime()
{

}

void DrawDateAndTime::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }

}

void DrawDateAndTime::drawBackIcon(QPainter *painter, myQRect *rect)
{

    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }
}

void DrawDateAndTime::drawTitle(QPainter *painter, myQRect *rect, QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawDateAndTime::drawDateAndTimeItems(QPainter *painter, QList<SystemItems*> *itemlist,dateModel *date)
{
    font.setPixelSize(20);
    painter->setFont(font);
    for(int i=0;i<itemlist->size();i++){
        painter->drawRect(itemlist->at(i)->itemrect);
        painter->drawText(itemlist->at(i)->itemtextrect,itemlist->at(i)->getItem_text_text());
        if(i==0)
        painter->drawText(itemlist->at(i)->itemiconrect,date->getDate());
        if(i==1)
             painter->drawText(itemlist->at(i)->itemiconrect,date->getTimehour());

    }

}
