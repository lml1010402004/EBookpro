#ifndef DRAWCONFIMDIALOG_H
#define DRAWCONFIMDIALOG_H
#include<QPainter>
#include<QRect>

class drawConfimDialog
{
public:
    drawConfimDialog(QWidget *parent);
   ~drawConfimDialog();

    void drawConfirmDialogTitle(QPainter *painter,int title);

    void drawYesAndNoButtons(QPainter *painter);

private:
    QRect rect;

};

#endif // DRAWCONFIMDIALOG_H
