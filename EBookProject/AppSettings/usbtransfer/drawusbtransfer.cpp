#include "drawusbtransfer.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;


const QString USB_LOGO = ":/pic/pics/usb_transfer.png";

DrawUsbtransfer::DrawUsbtransfer()
{

}

DrawUsbtransfer::~DrawUsbtransfer()
{

}

void DrawUsbtransfer::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }

}

void DrawUsbtransfer::drawBackIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }
}

void DrawUsbtransfer::drawTitle(QPainter *painter, myQRect *rect,QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawUsbtransfer::drawLogo(QPainter *painter, myQRect *rect)
{
    painter->drawPixmap(rect->rect,USB_LOGO);
}

void DrawUsbtransfer::drawState(QPainter *painter, myQRect *rect,QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawUsbtransfer::drawDataTransferOrChargeOnly(QPainter *painter, myQRect *rect,QString str)
{
    if(rect->isPressed){
        painter->fillRect(rect->rect,Qt::black);
    }
    painter->drawRoundedRect(rect->rect,3,3);
    QRect temprect;
    temprect.setX(rect->rect.x()+25);
    temprect.setY(rect->rect.y()+10);
    temprect.setWidth(rect->rect.width());
    temprect.setHeight(rect->rect.height());
    painter->drawText(temprect,str);
}


