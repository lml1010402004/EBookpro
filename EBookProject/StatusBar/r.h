#ifndef R_H
#define R_H
#include"redefineqrect.h"
#define PULLDOWN_WIFI 0
#define PULLDOWN_SETTING 1
#define PULLDOWN_SEARCH 2
#define PULLDOWN_MINUS 3
#define PULLDOWN_PLUS 4
#define PULLDOWN_UP 5
#define PULLDOWN_DOWN 6
#define PULLDOWN_RECTANGLE 7

class R
{
public:
    R();
    static void assignMacroDefinitions(myQRect *myrect,int i);
};

#endif // R_H
