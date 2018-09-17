#include "rfile.h"
#include"application.h"

RFIle::RFIle()
{

}

void RFIle::assignMacroDefinition(int module, myQRect *rect, int index)
{
    switch (module) {
    case LIGHT_INDEX:
        switch (index) {
        case 0:
            rect->xid = LIGHT_BACKICON;
            break;
        case 1:
            rect->xid = LIGHT_HOMEICON;
            break;
        case 2:
            rect->xid = LIGHT_HOMETITLE;
            break;
        case 3:
            rect->xid = LIGHT_MINUS;
            break;
        case 4:
            rect->xid  = LIGHT_PLUS;
            break;
        default:
            break;
        }

        break;
    case WALLPAPER_INDEX:
        switch (index) {
        case 0:
           rect->xid = WALLPAPER_BACKICON;
            break;
        case 1:
            rect->xid = WALLPAPER_HOMEICON;
            break;
        case 2:
            rect->xid = WALLPAPER_TITLE;
            break;
        default:
            break;
        }
        break;
    case NETWORK_INDEX:
        switch (index) {
        case 0:
            rect->xid = NETWORK_BACKICON;
            break;
        case 1:
            rect->xid = NETWORK_HOMEICON;
            break;
        case 2:
            rect->xid = NETWORK_TITLE;
            break;
        case 3:
            rect->xid = NETWORK_WIFITEXT;
            break;
        case 4:
            rect->xid = NETWORK_WIFISWITCH;
            break;
        case 5:
            rect->xid = NETWORK_SEARCHRESULT_TEXT;
            break;
        default:
            break;
        }
        break;
    case USBTRANSFER_INDEX:
        switch (index) {
        case 0:
            rect->xid = USB_BACKICON;
            break;
        case 1:
            rect->xid = USB_HOMEICON;
            break;
        case 2:
            rect->xid = USB_TITLE;
            break;
        case 3:
            rect->xid = USB_ICON;
            break;
        case 4:
            rect->xid = USB_STATE;
            break;
        case 5:
            rect->xid = USB_DATATRANSFER;
            break;
        case 6:
            rect->xid = USB_CHRGE;
            break;
        default:
            break;
        }

        break;
    case DATEANDTIME_INDEX:
        switch (index) {
        case 0:
            rect->xid = DATEANDTIME_BACKICON;
            break;
        case 1:
            rect->xid = DATEANDTIME_HOMEICON;
            break;
        case 2:
            rect->xid = DATEANDTIME_TITLE;
            break;
        default:
            break;
        }

        break;
    case LANGUAGE_INDEX:
        switch (index) {
        case 0:
            rect->xid = LANGUAGEKEYBOARD_BACKICON;
            break;
        case 1:
            rect->xid = LANGUAGKEYBODRD_HOMEICON;
            break;
        case 2:
            rect->xid = LANGUAGEKEBOARD_TITLE;
            break;
        default:
            break;
        }

        break;
    case RESTORE_INDEX:
        switch (index) {
        case 0:
            rect->xid = RESTORE_BACKICON;
            break;
        case 1:
            rect->xid = RESTORE_HOMEICON;
            break;
        case 2:
            rect->xid = RESTORE_TEXT;
            break;
        case 3:
            rect->xid = RESTORE_CONFIRM_BUTTON;
            break;
        default:
            break;
        }
        break;
    case OTHER_INDEX:
        switch (index) {
        case 0:
            rect->xid = OTHER_BACKICON;
            break;
        case 1:
            rect->xid = OTHER_HOMEICON;
            break;
        case 2:
            rect->xid = OTHER_TITLE;
            break;
        default:
            break;
        }

        break;
    default:
        break;
    }

}

