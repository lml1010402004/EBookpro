#include "confirmdialog.h"
#include<QHBoxLayout>
#include<QProcess>

const int dialog_width = 400;
const int dialog_height = 300;
const int dialog_x = 100;
const int dialog_y = 150;
const int yesbutton_x =45 ;
const int yesbutton_y =170;
const int yesbutton_w =120;
const int yesbutton_h = 40;
const int nobutton_x =235;





extern void formattingDisk();


confirmDialog::confirmDialog(QWidget *parent):QDialog(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);

    init();

    this->setGeometry(QRect(dialog_x,dialog_y,dialog_width,dialog_height));
    QHBoxLayout *midlayout = new QHBoxLayout;
    midlayout->setGeometry(QRect(0,0,dialog_width,dialog_height));

    setLayout(midlayout);
}

confirmDialog::~confirmDialog()
{
    delete drawconfirmdialog;
}

void confirmDialog::init()
{
    drawconfirmdialog = new drawConfimDialog(this);
    dialogrect.setX(0);
    dialogrect.setY(0);
    dialogrect.setWidth(dialog_width-2);
    dialogrect.setHeight(dialog_height-2);

    yesbutton = new myQRect;
    yesbutton->rect.setX(yesbutton_x);
    yesbutton->rect.setY(yesbutton_y);
    yesbutton->rect.setWidth(yesbutton_w);
    yesbutton->rect.setHeight(yesbutton_h);
    yesbutton->isPressed = false;

    nobutton = new myQRect;
    nobutton->rect.setX(nobutton_x);
    nobutton->rect.setY(yesbutton_y);
    nobutton->rect.setWidth(yesbutton_w);
    nobutton->rect.setHeight(yesbutton_h);
    nobutton->isPressed = false;

}

void confirmDialog::paintEvent(QPaintEvent *event)
{
    QPainter  *painter = new QPainter(this);
    painter->drawRect(dialogrect);
    drawconfirmdialog->drawConfirmDialogTitle(painter,tr("Restore"));
    drawconfirmdialog->drawYesAndNoButtons(painter,yesbutton,tr("Yes"),nobutton,tr("No"));

}


/**
 * @brief confirmDialog::mousePressEvent
 * @param event
 */
void confirmDialog::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(x>yesbutton->rect.x()&&x<yesbutton->rect.x()+yesbutton->rect.width()&&y>yesbutton->rect.y()&&y<yesbutton->rect.y()+yesbutton->rect.height()){
        yesbutton->isPressed = true;
        this->repaint();
    }
    if(x>nobutton->rect.x()&&x<nobutton->rect.x()+nobutton->rect.width()&&y>nobutton->rect.y()&&y<nobutton->rect.y()+nobutton->rect.height()){
        nobutton->isPressed = true;
        this->repaint();
    }

}

void confirmDialog::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(x>yesbutton->rect.x()&&x<yesbutton->rect.x()+yesbutton->rect.width()&&y>yesbutton->rect.y()&&y<(yesbutton->rect.y()+yesbutton->rect.height())){
        yesbutton->isPressed = false;
        formattingDisk();
        this->close();
    }
    if(x>nobutton->rect.x()&&x<nobutton->rect.x()+nobutton->rect.width()&&y>nobutton->rect.y()&&y<nobutton->rect.y()+nobutton->rect.height()){
        nobutton->isPressed = false;
        this->close();
    }

}
