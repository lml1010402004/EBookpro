#include "drawwallpaper.h"
#include"utils/application.h"

extern const  QString home_pressed;
extern const QString home_unpress;

extern const QString back_unpress;
extern const QString back_pressed;


DrawWallpaper::DrawWallpaper()
{

}

DrawWallpaper::~DrawWallpaper()
{

}

void DrawWallpaper::drawHomeIcon(QPainter *paitner,myQRect rect)
{
    if(rect.isPressed){
        paitner->drawPixmap(rect.rect,home_pressed);
    }else{
        paitner->drawPixmap(rect.rect,home_unpress);
    }

}

void DrawWallpaper::drawBackIcon(QPainter *painter,myQRect rect)
{
    if(rect.isPressed){
      painter->drawPixmap(rect.rect,back_pressed);
    }else{
      painter->drawPixmap(rect.rect,back_unpress);
    }
}

void DrawWallpaper::drawWallPapaerItem(QPainter *painter, int index)
{

}
