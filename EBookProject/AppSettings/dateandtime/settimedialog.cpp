#include "settimedialog.h"
#include<QHBoxLayout>
#include<QRegExp>
#include<QRegExpValidator>
#include<QPainter>
#include<rfile.h>
#include"utils/application.h"
#include"commonutils.h"
#include<QProcess>

const int TIMEDIALOG_X[] = {180,30,230};
const int TIMEDIALOG_Y[] = {30,180,180};
const int TIMEDIALOG_W[] = {60,120,120};
const int TIMEDIALOG_HE[] = {40,40,40};

extern int dateorTime;


SetTimeDialog::SetTimeDialog(QWidget *parent):QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setGeometry(QRect(100,150,400,300));
    init();
    QHBoxLayout *leftlayout = new QHBoxLayout;
    leftlayout->addWidget(mylineedit1);
    leftlayout->setGeometry(QRect(60,116,60,40));
    QHBoxLayout *rightlayout = new QHBoxLayout;
    rightlayout->addWidget(mylineedit2);
    rightlayout->setGeometry(QRect(265,116,60,40));
    QHBoxLayout *totallayout = new QHBoxLayout;
    totallayout->addLayout(leftlayout);
    totallayout->addLayout(rightlayout);
    setLayout(totallayout);

}

SetTimeDialog::~SetTimeDialog()
{
    delete mylineedit1,mylineedit2;
}

void SetTimeDialog::init()
{

    targetwidgetIndex = -1;
    rectlist = new QList<myQRect*>;
    for(int i=0;i<3;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(TIMEDIALOG_X[i]);
        myqrect->rect.setY(TIMEDIALOG_Y[i]);
        myqrect->rect.setWidth(TIMEDIALOG_W[i]);
        myqrect->rect.setHeight(TIMEDIALOG_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(TIMEDIALOG,myqrect,i);
        rectlist->append(myqrect);
    }
    initView();
}

void SetTimeDialog::initView()
{

    mylineedit1 = new QLineEdit(this);
    mylineedit2 = new QLineEdit(this);
    mylineedit1->setMaxLength(4);
    mylineedit2->setMaxLength(4);
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, mylineedit1 );
    mylineedit1->setValidator( validator );
    QValidator *validator2 = new QRegExpValidator(regx, mylineedit2 );
    mylineedit2->setValidator(validator2);

    drawsettimedialog = new DrawSettimeDialog;

}

void SetTimeDialog::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    QRect rect(0,0,399,300);
    painter->drawRect(rect);

    if(dateorTime==0){
        drawsettimedialog->drawSettimeDialogTitle(painter,rectlist->at(TIMEDIALOG_TITLE),tr("Date"));
    }else if(dateorTime==1){
        drawsettimedialog->drawSettimeDialogTitle(painter,rectlist->at(TIMEDIALOG_TITLE),tr("Time"));
    }
    drawsettimedialog->drawYesAndNoButtons(painter,rectlist->at(TIMEDIALOG_YES),tr("Yes"),rectlist->at(TIMEDIALOG_NO),tr("No"));
}

void SetTimeDialog::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = true;
        this->repaint();
    }
}

void SetTimeDialog::mouseMoveEvent(QMouseEvent *event)
{

}

void SetTimeDialog::mouseReleaseEvent(QMouseEvent *event)
{
    QString str="";
    switch(targetwidgetIndex){
    case TIMEDIALOG_TITLE:
        break;
    case TIMEDIALOG_YES:
        if(dateorTime==0){//date
            QString str1 = mylineedit1->text();
            QString str2 = mylineedit2->text();
//            QStringList s = systemtime.split(" ");
//            str = "2018-"+str1+"-"+str2+" "+s.at(1);
        }else if(dateorTime==1){//time
            QString str1 = mylineedit1->text();
            QString str2 = mylineedit2->text();
            str = str1+":"+str2;
        }
        setDateandHourIntoSystem(str);
        break;
    case TIMEDIALOG_NO:
        this->close();
        break;
    }
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = false;
        targetwidgetIndex = -1;
        this->repaint();
    }
}

void SetTimeDialog::setDateandHourIntoSystem(QString time)
{
    if(!time.isEmpty()){
        QString m = QString("date -s ")+QString("\"")+time+QString("\"");

        QProcess::startDetached(m);
        QProcess::startDetached("hwclock -w");
        QProcess::startDetached("sync");
        emit closeWindows();
        this->close();
    }
}
