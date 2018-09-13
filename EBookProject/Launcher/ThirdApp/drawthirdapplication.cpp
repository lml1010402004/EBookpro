#include "drawthirdapplication.h"
#include<QDebug>
extern  QString home_pressed;
extern  QString home_unpress;


const QString item_icon_paths[] = {
    ":/mypic/pics/bg1.png",
    ":/mypic/pics/bg2.png",
    ":/mypic/pics/bg3.png",
    ":/mypic/pics/bg1.png"
};

const QString item_pressed[] = {
    ":/mypic/pics/bg2.png",
    ":/mypic/pics/bg2.png",
    ":/mypic/pics/bg2.png",
    ":/mypic/pics/bg2.png"
};


DrawThirdApplication::DrawThirdApplication()
{

}

DrawThirdApplication::~DrawThirdApplication()
{

}

void DrawThirdApplication::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawThirdApplication::drawAppsText(QPainter *painter, QString text, myQRect *rect)
{
  painter->drawText(rect->rect,text);
}

void DrawThirdApplication::drawAppsItems(QPainter *painter, QList<SystemItems *> *itemlist)
{
    if(itemlist->size()==0){
        return;
    }
    font.setPixelSize(20);
    painter->setFont(font);
    for(int i=0;i<itemlist->size();i++){
        painter->drawRect(itemlist->at(i)->itemrect);
        painter->drawText(itemlist->at(i)->itemtextrect,itemlist->at(i)->getItem_text_text());
        if(itemlist->at(i)->ispressed){
            painter->drawPixmap(itemlist->at(i)->itemiconrect,item_pressed[i]);
        }else{
            painter->drawPixmap(itemlist->at(i)->itemiconrect,item_icon_paths[i]);
        }
    }

}
