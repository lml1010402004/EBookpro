#ifndef SCREENSLEEP_H
#define SCREENSLEEP_H

#include <QObject>
#include <QTimer>


//#include"sysmsg.h"

class ScreenSleep : public QObject
{
    Q_OBJECT
public:
    ScreenSleep(int screen_timeout, int sleep_timeout);
    bool hasTheTargetProcess();

signals:
    void signStopRun();

private slots:

    void onResetTimer();
    void onScreenTimeout();

private:
    QTimer *timer;
    int screenTimeout;
    int sleepTimeout;


//    Sysmsg msg;
};

#endif // SCREENSLEEP_H
