#include "drawothermodule.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;

DrawOtherModule::DrawOtherModule()
{

}

DrawOtherModule::~DrawOtherModule()
{

}

void DrawOtherModule::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawOtherModule::drawBackIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }

}

void DrawOtherModule::drawTitle(QPainter *painter, myQRect *rect,QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawOtherModule::drawOtherSettingItems(QPainter *painter, QList<SystemItems *> *itemlist)
{
    font.setPixelSize(20);
    painter->setFont(font);
    for(int i=0;i<itemlist->size();i++){
        painter->drawRect(itemlist->at(i)->itemrect);
        painter->drawText(itemlist->at(i)->itemtextrect,itemlist->at(i)->getItem_text_text());
//        if(itemlist->at(i)->ispressed){
//            painter->drawPixmap(itemlist->at(i)->itemiconrect,item_pressed[i]);
//        }else{
//            painter->drawPixmap(itemlist->at(i)->itemiconrect,item_icon_paths[i]);
//        }
    }

}
