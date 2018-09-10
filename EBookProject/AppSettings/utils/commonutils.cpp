#include "commonutils.h"

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


