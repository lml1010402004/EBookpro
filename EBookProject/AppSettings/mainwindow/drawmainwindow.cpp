#include "drawmainwindow.h"

const QString home_pressed=":/pic/pics/home_pressed.png";
const QString home_unpress = ":/pic/pics/home_unpress.png";


const QString item_icon_paths[] = {
    ":/pic/pics/light_unpress.png",
    ":/pic/pics/wallpaper_unpress.png",
    ":/pic/pics/network_unpress.png",
    ":/pic/pics/usb_unpress.png",
    ":/pic/pics/date_unpress.png",
    ":/pic/pics/language_unpress.png",
    ":/pic/pics/restore_unpress.png",
    ":/pic/pics/other_unpress.png"
};

const QString item_pressed[] = {
    ":/pic/pics/light_pressed.png",
    ":/pic/pics/wallpaper_pressed.png",
    ":/pic/pics/network_pressed.png",
    ":/pic/pics/usb_pressed.png",
    ":/pic/pics/date_pressed.png",
    ":/pic/pics/language_pressed.png",
    ":/pic/pics/restore_pressed.png",
    ":/pic/pics/other_pressed.png"
};





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
            painter->drawPixmap(itemlist->at(i)->itemiconrect,item_pressed[i]);
        }else{
            painter->drawPixmap(itemlist->at(i)->itemiconrect,item_icon_paths[i]);
        }
    }

}
