#include "drawconfimdialog.h"
#include<QString>

drawConfimDialog::drawConfimDialog(QWidget *parent)
{

}

drawConfimDialog::~drawConfimDialog()
{

}


void drawConfimDialog::drawConfirmDialogTitle(QPainter *painter, int title)
{
    rect.setX(160);
    rect.setY(33);
    rect.setWidth(120);
    rect.setHeight(40);
    QString temp="";
    if(title==0){
        temp = QObject::tr("Restore");
    }else if(title==1){
        temp = QObject::tr("ShutDown");
    }
    painter->drawText(rect,temp);

}

void drawConfimDialog::drawYesAndNoButtons(QPainter *painter)
{

    rect.setX(45);
    rect.setY(170);
    rect.setWidth(120);
    rect.setHeight(40);
    painter->drawRect(rect);
    rect.setX(85);
    rect.setY(173);
    rect.setWidth(110);
    rect.setHeight(34);
    painter->drawText(rect,QObject::tr("Yes"));

    rect.setX(235);
    rect.setY(170);
    rect.setWidth(120);
    rect.setHeight(40);
    painter->drawRect(rect);
    rect.setX(275);
    rect.setWidth(110);
    rect.setY(173);
    rect.setHeight(34);
    painter->drawText(rect,QObject::tr("No"));
}
