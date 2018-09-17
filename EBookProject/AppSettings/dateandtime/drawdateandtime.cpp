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

void DrawDateAndTime::drawDateAndTimeItems(QPainter *painter, dateModel *date)
{

}
