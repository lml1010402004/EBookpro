#include "commonutils.h"
#include<QDateTime>
#include<QTime>
commonUtils::commonUtils()
{

}

int commonUtils::getTargetIndexInSettingModule(int x, int y, QList<SystemItems *> *list)
{
  int tmp = -1;
  for(int i=0;i<list->size();i++){
      if(y>list->at(i)->itemrect.y()&&y<(list->at(i)->itemrect.y()+list->at(i)->itemrect.height())){
          tmp = i;
      }
  }
  return tmp;
}

int commonUtils::getTheTargetWidget(int pos_x, int pos_y, QList<myQRect *> *rectlist){

    int targetwidgetindex = -1;

    for(int i=0;i<rectlist->size();i++){
        if(pos_x>rectlist->at(i)->rect.x()&&pos_x<rectlist->at(i)->rect.x()+rectlist->at(i)->rect.width()
                &&pos_y>rectlist->at(i)->rect.y()&&pos_y<rectlist->at(i)->rect.y()+rectlist->at(i)->rect.height()){
            targetwidgetindex = i;
            break;
        }
    }
    return targetwidgetindex;
}

QString commonUtils::getCurrentTime(){
    QString systemtime;
    systemtime = QDateTime::currentDateTime().toString("MM-dd hh:mm");
   return systemtime;
}


