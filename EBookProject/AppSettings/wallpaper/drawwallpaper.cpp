#include "drawwallpaper.h"
#include"utils/application.h"

extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;
const QString WALLPAPERGROUP[3] = {":/pic/pics/sleep_bg2.png",":/pic/pics/sleep_bg3.png",":/pic/pics/sleep_bg4.png"};
const QString CHECKBOX = ":/pic/pics/checkbox_true.png";


DrawWallPaper::DrawWallPaper()
{

}

DrawWallPaper::~DrawWallPaper()
{

}

void DrawWallPaper::drawHomeIcon(QPainter *painter,myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawWallPaper::drawBackIcon(QPainter *painter,myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }

}

void DrawWallPaper::drawWallPapaerItem(QPainter *painter, int index)
{

}

void DrawWallPaper::drawTitle(QPainter *painter, myQRect *rect, QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawWallPaper::drawWallPapers(QPainter *painter, QList<myQRect*> *list)
{
    for(int i=0;i<list->size();i++){
        painter->drawPixmap(list->at(i)->rect,WALLPAPERGROUP[i]);
        QRect temp;
        temp.setX(list->at(i)->rect.x()-1);
        temp.setY(list->at(i)->rect.y()+1);
        temp.setWidth(list->at(i)->rect.width()-1);
        temp.setHeight(list->at(i)->rect.height()-1);
        painter->drawRect(temp);

    }

}

void DrawWallPaper::drawCheckbox(QPainter *painter, QList<myQRect *> *list,int checked_index)
{
    for(int i=0;i<list->size();i++){
        if(i==checked_index){
            painter->drawPixmap(list->at(i)->rect,CHECKBOX);
        }else{
            painter->drawRect(list->at(i)->rect);
        }
    }

}
