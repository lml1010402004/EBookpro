#include "drawbrightness.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;

const QString minus_unpress=":/pic/pics/minus_uppress.png";
const QString minus_pressed=":/pic/pics/minus_pressed.png";
const QString plus_unpress=":/pic/pics/plus_unpress.png";
const QString plus_pressed=":/pic/pics/plus_pressed.png";

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
        painter->drawPixmap(rect->rect,minus_pressed);

    }else{
        painter->drawPixmap(rect->rect,minus_unpress);
    }
}

void DrawBrightness::drawPlusButton(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,plus_pressed);
    }else{
        painter->drawPixmap(rect->rect,plus_unpress);
    }

}
