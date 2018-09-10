#include "drawmainwindow.h"

const QString home_pressed=":/pic/pics/home_pressed.png";
const QString home_unpress = ":/pic/pics/home_unpress.png";


const QString item_icon_paths[] = {
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png"
};

const QString path_pressed = ":/pic/pics/network_icon_pressed.png";



DrawMainWindow::DrawMainWindow()
{

}

DrawMainWindow::~DrawMainWindow()
{

}

void DrawMainWindow::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawMainWindow::drawSystemSettingText(QPainter *painter, QString text, myQRect *rect)
{
    painter->drawText(rect->rect,text);
}

void DrawMainWindow::drawSettingItems(QPainter *painter, QList<SystemItems*> *itemlist)
{
    font.setPixelSize(20);
    painter->setFont(font);
    for(int i=0;i<itemlist->size();i++){
        painter->drawRect(itemlist->at(i)->itemrect);
        painter->drawText(itemlist->at(i)->itemtextrect,itemlist->at(i)->getItem_text_text());
        if(itemlist->at(i)->ispressed){
            painter->drawPixmap(itemlist->at(i)->itemiconrect,path_pressed);
        }else{
            painter->drawPixmap(itemlist->at(i)->itemiconrect,item_icon_paths[i]);
        }
    }

}
