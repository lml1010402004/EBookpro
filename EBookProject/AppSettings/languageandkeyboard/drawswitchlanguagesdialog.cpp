#include "drawswitchlanguagesdialog.h"

DrawSwitchLanguagesDialog::DrawSwitchLanguagesDialog()
{

}

DrawSwitchLanguagesDialog::~DrawSwitchLanguagesDialog()
{

}

void DrawSwitchLanguagesDialog::drawLanguagesItems(QPainter *painter, QList<myQRect*> *rectlist, QString items[])
{
    for(int i=0;i<rectlist->size();i++){
        painter->drawRect(rectlist->at(i)->rect);
        QRect rect;
        rect.setX(rectlist->at(i)->rect.x()+10);
        rect.setY(rectlist->at(i)->rect.y()+10);
        rect.setWidth(rectlist->at(i)->rect.width());
        rect.setHeight(rectlist->at(i)->rect.height());
        painter->drawText(rect,items[i]);
    }

}


