#include "switchlanguagedialog.h"
#include"commonutils.h"
#include<QTranslator>
#include<QApplication>

QString languagesgroup[] = {QObject::tr("English"),QObject::tr("Chinese")};

const int items_x = 10;
const int items_y = 10;
const int items_w = 100;
const int items_he = 60;

QTranslator qtTranslator;
SwitchLanguageDialog::SwitchLanguageDialog()
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setGeometry(QRect(450,150,120,150));
    this->setFixedHeight(150);
    this->setFixedWidth(120);

    init();

}

SwitchLanguageDialog::~SwitchLanguageDialog()
{
    for(int i=0;i<rectlist->size();i++){
        delete rectlist->at(i);
    }
  delete mysetting,myqrect;
}

void SwitchLanguageDialog::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    drawswitchdialog->drawLanguagesItems(painter,rectlist,languagesgroup);

}

void SwitchLanguageDialog::mousePressEvent(QMouseEvent *event)
{

}

void SwitchLanguageDialog::mouseReleaseEvent(QMouseEvent *event)
{
    int x= event->x();
    int y = event->y();
   targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
   if(targetwidgetIndex>-1){

       if(targetwidgetIndex==0){
           qtTranslator.load(":/pic/setting_en.qm");
           QApplication::installTranslator(&qtTranslator);
           mysetting->setLanguage("English");
       }else if(targetwidgetIndex ==1){
           qtTranslator.load(":/pic/setting_cn.qm");
           QApplication::installTranslator(&qtTranslator);
           mysetting->setLanguage("Chinese");
       }

       targetwidgetIndex = -1;
       this->close();
   }


}

void SwitchLanguageDialog::init()
{

    mysetting = new SysSettings;
    rectlist = new QList<myQRect*>;
  for(int i=0;i<2;i++){
      myqrect = new myQRect;
      myqrect->rect.setX(items_x);
      myqrect->rect.setY(items_y+i*items_he);
      myqrect->rect.setWidth(items_w);
      myqrect->rect.setHeight(items_he);
      rectlist->append(myqrect);
  }

  drawswitchdialog = new DrawSwitchLanguagesDialog;

}
