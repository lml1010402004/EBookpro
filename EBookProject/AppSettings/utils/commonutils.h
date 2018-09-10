#ifndef COMMONUTILS_H
#define COMMONUTILS_H
#include"dataitem/systemitems.h"
#include<QList>

class commonUtils
{
public:
    commonUtils();

  static  int getTargetIndexInSettingModule(int x,int y ,QList<SystemItems*> *list);
};

#endif // COMMONUTILS_H
