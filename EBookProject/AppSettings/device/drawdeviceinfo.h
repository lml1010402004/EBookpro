#ifndef DRAWDEVICEINFO_H
#define DRAWDEVICEINFO_H
#include<QPainter>
#include"utils/redefineqrect.h"

class DrawDeviceInfo
{
public:
    DrawDeviceInfo();
    ~DrawDeviceInfo();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawDeviceInfoTitle(QPainter *painter,myQRect *rect,QString str);
    void drawDeviceInfoList(QPainter *painter,QString group[],QString group1[]);

};

#endif // DRAWDEVICEINFO_H
