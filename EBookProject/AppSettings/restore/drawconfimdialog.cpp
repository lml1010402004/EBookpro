#include "drawconfimdialog.h"
#include<QString>

drawConfimDialog::drawConfimDialog(QWidget *parent)
{

}

drawConfimDialog::~drawConfimDialog()
{

}


void drawConfimDialog::drawConfirmDialogTitle(QPainter *painter, QString title)
{
    rect.setX(160);
    rect.setY(33);
    rect.setWidth(120);
    rect.setHeight(40);
    painter->drawText(rect,title);

}

void drawConfimDialog::drawYesAndNoButtons(QPainter *painter, myQRect *yesbutton, QString yes, myQRect *nobutton, QString no)
{
    if(yesbutton->isPressed){
        painter->fillRect(yesbutton->rect,Qt::black);
    }
    if(nobutton->isPressed){
        painter->fillRect(nobutton->rect,Qt::black);
    }
    painter->drawRoundedRect(yesbutton->rect,3,3);
    painter->drawRoundedRect(nobutton->rect,3,3);
    QRect yesrect;
    yesrect.setX(yesbutton->rect.x()+40);
    yesrect.setY(yesbutton->rect.y()+5);
    yesrect.setWidth(yesbutton->rect.width());
    yesrect.setHeight(yesbutton->rect.height());
    painter->drawText(yesrect,yes);

    QRect norect;
    norect.setX(nobutton->rect.x()+40);
    norect.setY(nobutton->rect.y()+5);
    norect.setWidth(nobutton->rect.width());
    norect.setHeight(nobutton->rect.height());
    painter->drawText(norect,no);

}


