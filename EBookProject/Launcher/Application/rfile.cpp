#include "rfile.h"
#include"Application/application.h"

RFIle::RFIle()
{

}

void RFIle::assignMacroDefinition(int module, myQRect *rect, int index)
{
    switch (module) {
    case 0://represent HomePage module
        switch (index) {
        case 0:
            rect->xid =HPM_LEFTBOOK_RECT;
            break;
        case 1:
            rect->xid = HPM_RIGHTBOOK_RECT;
            break;
        case 2:
            rect->xid = HPM_LEFTBOOK_NAME_RECT;
            break;
        case 3:
            rect->xid = HPM_RIGHTBOOK_NAME_RECT;
            break;
        case 4:
            rect->xid = HPM_LEFTBOOK_AUTHOR_RECT;
            break;
        case 5:
            rect->xid = HPM_RIGHTBOOK_AUTHOR_RECT;
            break;
        case 6:
            rect->xid = HPM_NEW_BOOK;
            break;
        case 7:
            rect->xid = HPM_LASTPAGE_BUTTON;
            break;
        case 8:
            rect->xid = HPM_FIRSTBOOK_RECT;
            break;
        case 9:
            rect->xid = HPM_SECONDBOOK_RECT;
            break;
        case 10:
            rect->xid = HPM_THIRDBOOK_RECT;
            break;
        case 11:
            rect->xid = HPM_NEXTPAGE_BUTTON;
            break;
        case 12:
            rect->xid = HPM_FIRSTBOOK_NAME;
            break;
        case 13:
            rect->xid = HPM_SECONDBOOK_NAME;
            break;
        case 14:
            rect->xid = HPM_THIRDBOOK_NAME;
            break;
        case 15:
            rect->xid = HPM_BOOKSHELF_BUTTON;
            break;
        case 16:
            rect->xid = HPM_APP_BUTTON;
            break;
        case 17:
            rect->xid = HPM_SETTING_BUTTON;
            break;
        case 18:
            rect->xid = HPM_BOOKSHELF_NAME;
            break;
        case 19:
            rect->xid = HPM_APP_NAME;
            break;
        case 20:
            rect->xid = HPM_SETTING_NAME;
            break;
        default:
            break;
        }
        break;
    case 1://represent Bookshelf module

        break;
    default:
        break;
    }

}

