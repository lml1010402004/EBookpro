#include "drawsettimedialog.h"

DrawSettimeDialog::DrawSettimeDialog()
{

}

DrawSettimeDialog::~DrawSettimeDialog()
{

}

void DrawSettimeDialog::drawSettimeDialogTitle(QPainter *painter, myQRect *rect, QString title)
{
   painter->drawText(rect->rect,title);
}

void DrawSettimeDialog::drawYesAndNoButtons(QPainter *painter, myQRect *yes, QString yesstr, myQRect *no, QString nostr)
{
   painter->drawRect(yes->rect);
   painter->drawRect(no->rect);
   QRect rect;
   rect.setX(yes->rect.x()+40);
   rect.setY(yes->rect.y());
   rect.setWidth(yes->rect.width());
   rect.setHeight(yes->rect.height());
   painter->drawText(rect,yesstr);

   rect.setX(no->rect.x()+40);
   rect.setY(no->rect.y());
   rect.setWidth(no->rect.width());
   rect.setHeight(no->rect.height());
   painter->drawText(rect,nostr);

}
