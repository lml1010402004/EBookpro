#include <QDebug>
#include <fcntl.h>
#include <linux/input.h>
#include "eventthread.h"

EventThread::EventThread(QObject *parent) :
    QThread(parent)
{

}

EventThread::EventThread(QString node)
{
    isRun = true;
    eventNode = node;
}

void EventThread::onStopRun()
{
    isRun = false;
}

void EventThread::run()
{


        char* node;
        QByteArray ba = eventNode.toLatin1();
        node = ba.data();

        int fd = open(node, O_RDWR);
        if(fd <= 0)
        {
            qDebug() << "open " << node << " error!";
        }

        char buf[128] = {0};
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);

        while (isRun)
        {
            int ret = select(fd +1, &rfds, NULL, NULL, NULL);
            if (ret < 0)
            {
                continue;
            }

            if (FD_ISSET(fd, &rfds))
            {
                int readn = read(fd, buf, sizeof(struct input_event));
                if (readn <= 0)
                {
                    qDebug() << node << " read error!";
                    continue;
                }

                emit signResetTimer();
            }
        }

        close(fd);
        qDebug() << "stop listener " << node;

}
