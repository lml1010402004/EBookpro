#include "commonutils.h"
#include <sys/statfs.h>
#include <sys/socket.h>
#include <net/if.h>       /* for ifconf */
#include <linux/sockios.h>    /* for net status mask */
#include <netinet/in.h>       /* for sockaddr_in */
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <QApplication>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<QString>





QString HOME_PIC_PATH;
const QString FBReader_PATH = "/usr/local/FBReader/FBReader";
const QString FBReader_WORK_DIRECTORY = "/usr/local/FBReader";
const QString APPSETTINGS = "/usr/local/app/";

const QString Loading_path = ":/mypic/pics/loading.png";

extern QList<QMainWindow*> *mainwindowlist;

commonUtils::commonUtils()
{


}

int commonUtils::getStorageOfDevice()
{

    int storage_total_size=0;
    struct statfs diskInfo;
    statfs("/dev/block/by-name/UDISK", &diskInfo);
    unsigned long long blocksize = diskInfo.f_bsize; //每个block里包含的字节数
    storage_total_size =diskInfo.f_bavail * blocksize/1024;
    return storage_total_size;
}

QString  commonUtils::GetLocalMac()
{
    int sock_mac;

    struct ifreq ifr_mac;
    char mac_addr[30];

    sock_mac = socket( AF_INET, SOCK_STREAM, 0 );
    if( sock_mac == -1)
    {

        return "";
    }

    memset(&ifr_mac,0,sizeof(ifr_mac));
    strncpy(ifr_mac.ifr_name, "wlan0", sizeof(ifr_mac.ifr_name)-1);

    if( (ioctl( sock_mac, SIOCGIFHWADDR, &ifr_mac)) < 0)
    {
        return "";
    }

    sprintf(mac_addr,"%02x%02x%02x%02x%02x%02x",
            (unsigned char)ifr_mac.ifr_hwaddr.sa_data[0],
            (unsigned char)ifr_mac.ifr_hwaddr.sa_data[1],
            (unsigned char)ifr_mac.ifr_hwaddr.sa_data[2],
            (unsigned char)ifr_mac.ifr_hwaddr.sa_data[3],
            (unsigned char)ifr_mac.ifr_hwaddr.sa_data[4],
            (unsigned char)ifr_mac.ifr_hwaddr.sa_data[5]);

    close(sock_mac );
    return QString( mac_addr);
}


/**
 * @brief commonUtils::getCurrentPageBooks
 * @param list
 * @return
 */
QList<localDirectoryItem>* commonUtils::getCurrentPageBooks(QList<localDirectoryItem> *list,int currentPage,int pagesize)
{
    QList<localDirectoryItem> *templist = new QList<localDirectoryItem>;
    int totalpages =0;
    if(list->size()%pagesize==0){
        totalpages = list->size()/pagesize;
        //        qDebug()<<"totalpages111=="<<totalpages;
    }else{
        totalpages = list->size()/pagesize+1;
        //        qDebug()<<"totalpages222=="<<totalpages;
    }

    if(totalpages==0){

    }else if(totalpages==1&&currentPage==1){

        for(int i=0;i<list->size();i++){
            templist->append(list->at(i));
        }

    }else if(totalpages>1&&currentPage==1){
        for(int i=0;i<pagesize;i++){
            templist->append(list->at(i));
        }

    }else if(totalpages>1&&currentPage<totalpages){
        for(int i=0;i<pagesize;i++){
            templist->append(list->at((currentPage-1)*pagesize+i));
        }

    }else if(totalpages>1&&currentPage==totalpages){

        int temp = list->size()%pagesize;
        //          qDebug()<<"temp=="<<temp;
        if(temp==0){
            temp=9;
        }
        for(int i=0;i<temp;i++){
            templist->append(list->at((totalpages-1)*pagesize+i));
        }
        //        qDebug()<<"templist.size()=="<<templist->size();
    }
    return templist;
}


/**
 * @brief commonUtils::openBookFromFBreader
 * @param bookpath
 */
void commonUtils::openBookFromFBreader(QProcess *mprocess,QString bookpath)
{
    //    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新


    arguments.clear();
    arguments<<QStringList(bookpath);//actually ,here ,books_cover_path == books_path;
    mprocess->setEnvironment(mprocess->environment());
    mprocess->setWorkingDirectory(FBReader_WORK_DIRECTORY);

    mprocess->start(FBReader_PATH,arguments);

}


/**
 * @brief commonUtils::openSettingApp
 * @param process
 * @param apppath
 */
void commonUtils::openSettingApp(QProcess *process, QString apppath)
{
    process->setEnvironment(process->environment());
    process->setWorkingDirectory(APPSETTINGS);
    process->start(apppath);


}


/**
 * @brief commonUtils::drawProgressBarOpeningBook
 * @param painter
 */
void commonUtils::drawProgressBarOpeningBook(QPainter *painter)
{
    QRect rect;
    rect.setX(285);
    rect.setY(340);
    rect.setWidth(31);
    rect.setHeight(40);
    painter->drawPixmap(rect,Loading_path);

}


/**
 * 获取电池值,这个函数按照原则,只有在主动刷新界面的时候,才调用.为了不刷新屏幕,省电.
 * @brief commonUtils::getTheBatteryPercentage
 * @return
 */
int commonUtils::getTheBatteryPercentage()
{

    int fd = -1;
    fd= open("/sys/class/power_supply/battery/voltage_now",O_RDONLY);
    char rbuf[8]={'\0'};
    if(fd==-1){
        qDebug()<<"read the voltage fail"<<fd;
        return -1;
    }
    read(fd,&rbuf,8);
    QString str = QString(rbuf);
    str = str.mid(0,2);
    int temp = str.toInt(0,10);
    ::close(fd);//这个是c标准
    return temp;

}


/**
 * @brief commonUtils::getTheTargetWidget
 * @param pos_x
 * @param pos_y
 * @param listrect
 * @return
 */
int commonUtils::getTheTargetWidget(int pos_x, int pos_y, QList<myQRect*> *rectlist)
{
    int targetwidgetindex = -1;
qDebug()<<"rectlist.size()==="<<rectlist->size();
    for(int i=0;i<rectlist->size();i++){
        if(pos_x>rectlist->at(i)->rect.x()&&pos_x<rectlist->at(i)->rect.x()+rectlist->at(i)->rect.width()
                &&pos_y>rectlist->at(i)->rect.y()&&pos_y<rectlist->at(i)->rect.y()+rectlist->at(i)->rect.height()){
            targetwidgetindex = i;
            break;
        }
    }
    return targetwidgetindex;
}

void commonUtils::formattingDisk()
{
   system("umount /user");
   sleep(1);
   system("mkfs.vfat /dev/block/by-name/UDISK");
   sleep(1);
   system("reboot");
}

void commonUtils::backToHomePageSlot()
{
    int size = mainwindowlist->size();
    if(size>0){
        for(int i=0;i<size;i++){
            if(mainwindowlist->at(i)!=NULL){
                mainwindowlist->at(i)->close();
            }
        }
    }

}

int commonUtils::returnLightValue(int progress)
{
    //the start x point = 200
        int tempValue = (progress-200)/8;
        if((progress-200)%8!=0){
            tempValue++;
        }
        return tempValue;
}





QList<localDirectoryItem>* getCurrentPageBooks(QList<localDirectoryItem> *list,int currentPage,int pagesize){
  QList<localDirectoryItem> *templist = new QList<localDirectoryItem>;
  int totalpages = 0;
  if(list->size()%pagesize==0){
      totalpages = list->size()/pagesize;
  }else{
      totalpages = list->size()/pagesize+1;
  }

  if(totalpages==0){

  }else if(totalpages==1&&currentPage==1){

      for(int i=0;i<list->size();i++){
          templist->append(list->at(i));
      }

  }else if(totalpages>1&&currentPage==1){
      for(int i=0;i<pagesize;i++){
          templist->append(list->at(i));
      }

  }else if(totalpages>1&&currentPage<totalpages){
      for(int i=0;i<pagesize;i++){
          templist->append(list->at((currentPage-1)*pagesize+i));
      }

  }else if(totalpages>1&&currentPage==totalpages){

      int temp = list->size()%pagesize;
//          qDebug()<<"temp=="<<temp;
        if(temp==0){
            temp=9;
        }
      for(int i=0;i<temp;i++){
          templist->append(list->at((totalpages-1)*pagesize+i));
      }
//        qDebug()<<"templist.size()=="<<templist->size();
  }
  return templist;



}

int commonUtils::getTargetIndexInSettingModule(int x, int y, QList<SystemItems *> *list){
    int tmp = -1;
    for(int i=0;i<list->size();i++){
        if(y>list->at(i)->itemrect.y()&&y<(list->at(i)->itemrect.y()+list->at(i)->itemrect.height())){
            tmp = i;
        }
    }
    return tmp;
}






