#include "drawconnectwifidialog.h"

DrawConnectWifiDialog::DrawConnectWifiDialog()
{

}

DrawConnectWifiDialog::~DrawConnectWifiDialog()
{

}

void DrawConnectWifiDialog::drawTargetWifiTitle(QPainter *painter, myQRect *rect, QString title)
{
  painter->drawText(rect->rect,title);
}

void DrawConnectWifiDialog::drawDialogRect(QPainter *painter, myQRect rect)
{
  painter->drawRect(rect.rect);
}

void DrawConnectWifiDialog::drawWifiText(QPainter *painter, myQRect *rect, QString str)
{
painter->drawText(rect->rect,str);
}

void DrawConnectWifiDialog::drawConnOrCancleButton(QPainter *painter, myQRect *rect, QString str)
{
   font.setPointSize(12);
   painter->setFont(font);
   painter->drawRoundedRect(rect->rect,3,3);
  if(rect->isPressed){
    painter->fillRect(rect->rect,Qt::black);
  }
  QRect temp;
  temp.setX(rect->rect.x()+25);
  temp.setY(rect->rect.y()+5);
  temp.setWidth(rect->rect.width());
  temp.setHeight(rect->rect.height());
  painter->drawText(temp,str);
}


