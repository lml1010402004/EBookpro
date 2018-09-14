#include "rfile.h"
#include"Application/application.h"

RFIle::RFIle()
{

}

void RFIle::assignMacroDefinition(int module, myQRect *rect, int index)
{
    switch (module) {
    case HOME_PAGE_MODULE://represent HomePage module
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
    case BOOK_SHELF_MODULE://represent Bookshelf module
        switch (index) {
        case 0:
            rect->xid = BSM_SEARCH_BUTTON;
            break;
        case 1:
            rect->xid = BSM_HOME_BUTTON;
            break;
        case 2:
            rect->xid = BSM_TEXT;
            break;
        case 3:
            rect->xid= BSM_READ_ORDER_ITEM;
            break;
        case 4:
            rect->xid = BSM_READ_BOOK_NAME;
            break;
        case 5:
            rect->xid = BSM_READ_TIME;
            break;
        case 6:
            rect->xid = BSM_READ_BOOK_AUTHOR;
            break;
        case 7:
            rect->xid = BSM_FIRST_PAGE;
            break;
        case 8:
            rect->xid = BSM_LAST_PAGE;
            break;
        case 9:
            rect->xid = BSM_PAGES_CONTENT;
            break;
        case 10:
            rect->xid =BSM_NEXT_PAEG;
            break;
        case 11:
            rect->xid = BSM_END_PAGE;
            break;
        default:
            break;
        }

        break;
    default:
        break;
    }

}

