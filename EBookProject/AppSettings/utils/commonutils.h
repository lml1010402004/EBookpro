#ifndef COMMONUTILS_H
#define COMMONUTILS_H
#include"dataitem/systemitems.h"
#include<QList>
#include"utils/redefineqrect.h"

class commonUtils
{
public:
    commonUtils();

    static  int getTargetIndexInSettingModule(int x,int y ,QList<SystemItems*> *list);
    static int getTheTargetWidget(int pos_x,int pos_y,QList<myQRect*> *listrect);

    static QString getCurrentTime();

};

#endif // COMMONUTILS_H
