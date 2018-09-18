#include "drawrestore.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;
DrawRestore::DrawRestore()
{

}

DrawRestore::~DrawRestore()
{

}

void DrawRestore::drawTitle(QPainter *painter, myQRect *rect,QString title)
{
  painter->drawText(rect->rect,title);
}

void DrawRestore::drawBackIcon(QPainter *painter, myQRect *rect)
{

    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }
}

void DrawRestore::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawRestore::drawConfirmButton(QPainter *painter, myQRect *rect,QString str)
{
  if(rect->isPressed){
  painter->fillRect(rect->rect,Qt::black);
  }
  painter->drawRoundedRect(rect->rect,3,3);
  QRect temprect;
  temprect.setX(rect->rect.x()+20);
  temprect.setY(rect->rect.y()+16);
  temprect.setWidth(rect->rect.width());
  temprect.setHeight(rect->rect.height());
  painter->drawText(temprect,str);

}
