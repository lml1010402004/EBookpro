#ifndef POWERKEYDETECTTHREAD_H
#define POWERKEYDETECTTHREAD_H
#include<QThread>

class powerKeyDetectThread:public QThread
{
    Q_OBJECT
public:
    powerKeyDetectThread();

signals:
    void shutDownEBooksignal();
public slots:
protected:
   void run();
};

#endif // POWERKEYDETECTTHREAD_H
