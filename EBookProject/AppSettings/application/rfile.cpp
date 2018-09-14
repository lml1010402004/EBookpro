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
    case WALLPAPER_INDEX:
        break;
    case NETWORK_INDEX:
        break;
    case USBTRANSFER_INDEX:
        break;
    case DATEANDTIME_INDEX:
        break;
    case LANGUAGE_INDEX:
        break;
    case RESTORE_INDEX:
        break;
    case OTHER_INDEX:
        break;
    default:
        break;
    }

}

