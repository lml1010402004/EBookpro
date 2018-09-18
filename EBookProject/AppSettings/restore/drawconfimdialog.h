#ifndef DRAWCONFIMDIALOG_H
#define DRAWCONFIMDIALOG_H
#include<QPainter>
#include<QRect>
#include<utils/redefineqrect.h>

class drawConfimDialog
{
public:
    drawConfimDialog(QWidget *parent);
   ~drawConfimDialog();

    void drawConfirmDialogTitle(QPainter *painter,QString title);

    void drawYesAndNoButtons(QPainter *painter,myQRect *yesbutton,QString yes,myQRect *nobutton,QString no);

private:
    QRect rect;

};

#endif // DRAWCONFIMDIALOG_H
