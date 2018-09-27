#ifndef EVENTTHREAD_H
#define EVENTTHREAD_H

#include <QThread>
#include <QObject>
#include<QStringList>

class EventThread : public QThread
{
    Q_OBJECT
public:
    EventThread(QString node);
    explicit EventThread(QObject *parent = 0);

protected:
    void run();

signals:
    void signResetTimer();

private slots:
    void onStopRun();

private:
    QString eventNode;
    bool isRun;
};

#endif // EVENTTHREAD_H
