#include "drawwallpaper.h"
#include"utils/application.h"

extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;


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
//        painter->drawPixmap(list->at(i),"");
painter->drawRect(list->at(i)->rect);
    }

}
