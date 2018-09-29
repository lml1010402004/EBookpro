#include "r.h"

R::R()
{

}

void R::assignMacroDefinitions(myQRect *myrect, int i)
{
switch(i){
case 0:
    myrect->xid = PULLDOWN_WIFI;
    break;
case 1:
    myrect->xid = PULLDOWN_SETTING;
    break;
case 2:
    myrect->xid = PULLDOWN_SEARCH;
    break;
case 3:
    myrect->xid = PULLDOWN_MINUS;
    break;
case 4:
    myrect->xid = PULLDOWN_PLUS;
    break;
case 5:
    myrect->xid = PULLDOWN_UP;
    break;
case 6:
    myrect->xid = PULLDOWN_DOWN;
    break;
case 7:
    myrect->xid = PULLDOWN_RECTANGLE;
    break;
}

}
