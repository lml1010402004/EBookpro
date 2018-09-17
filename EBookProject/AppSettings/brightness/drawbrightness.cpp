#include "drawbrightness.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;



DrawBrightness::DrawBrightness()
{

}

DrawBrightness::~DrawBrightness()
{

}

void DrawBrightness::drawBackIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }
}

void DrawBrightness::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawBrightness::drawTitle(QPainter *painter, myQRect *rect,QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawBrightness::drawMinusButton(QPainter *painter, myQRect *rect)
{
  if(rect->isPressed){

  }else{

  }
}

void DrawBrightness::drawPlusButton(QPainter *painter, myQRect *rect)
{
  if(rect->isPressed){

  }else{

  }

}
