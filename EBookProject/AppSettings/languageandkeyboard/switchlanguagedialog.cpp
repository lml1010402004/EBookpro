#include "switchlanguagedialog.h"
#include"commonutils.h"

QString languagesgroup[] = {QObject::tr("English"),QObject::tr("Chinese")};

const int items_x = 10;
const int items_y = 10;
const int items_w = 100;
const int items_he = 60;

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
       targetwidgetIndex = -1;
       this->close();
   }
}

void SwitchLanguageDialog::init()
{
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
