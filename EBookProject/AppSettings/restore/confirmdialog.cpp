#include "confirmdialog.h"
#include<QHBoxLayout>
#include<QProcess>


extern int confirmdialogtitle;
extern void formattingDisk();

QString SleepApp = "/usr/local/app/SleepScreen";

confirmDialog::confirmDialog(QWidget *parent):QDialog(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);

    init();

    this->setGeometry(QRect(100,150,400,300));
    QHBoxLayout *midlayout = new QHBoxLayout;
    midlayout->setGeometry(QRect(0,0,400,300));

    setLayout(midlayout);
}

confirmDialog::~confirmDialog()
{
delete drawconfirmdialog;
}

void confirmDialog::init()
{
    drawconfirmdialog = new drawConfimDialog(this);

}

void confirmDialog::paintEvent(QPaintEvent *event)
{
// QPainter  *painter = new QPainter(this);
//    drawconfirmdialog->drawConfirmDialogTitle(painter,confirmdialogtitle);
//    drawconfirmdialog->drawYesAndNoButtons(painter);


}


/**
 * @brief confirmDialog::mousePressEvent
 * @param event
 */
void confirmDialog::mousePressEvent(QMouseEvent *event)
{

int x = event->x();
int y = event->y();


}

void confirmDialog::mouseReleaseEvent(QMouseEvent *event)
{

}
