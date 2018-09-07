#include "mainwindow.h"
#include"Application/application.h"
#include<QDebug>
#include"Utils/commonutils.h"
#include<QBrush>


const int mainapge_x[21] = {100,350,100,350,160,410,280,40,90,240,390,520,120,270,420,70,270,470,80,280,480};
const int mainpage_y[21] = {110,110,200,200,330,330,450,530,480,480,480,530,640,640,640,700,700,700,770,770,770};
const int mainpage_w[21] =   {150,150,150,150,60,60,40,40,120,120,120,40,80,80,80,64,64,64,60,60,60};
const int mainpage_h[21] =     {200,200,40,40,20,20,20,40,150,150,150,40,20,20,20,64,64,64,20,20,20};





const QString homeiconpath = ":/mypic/pics/homeicon.png";

const QString nextpage_path = ":/mypic/pics/nextpage_rectangle.png";
const QString lastpage_path = ":/mypic/pics/lastpage_rectangle.png";
const QString unable_next_path=":/mypic/pics/unable_next.png";
const QString unable_last_path=":/mypic/pics/unable_last.png";

const QString booklibray_path=":/mypic/pics/book_library.png";
const QString bookcity = ":/mypic/pics/bookcity.png";
const QString gamepath = ":/mypic/pics/game.png";

QList<QMainWindow*> *mainwindowlist;


const QString cover_group[3] = {":/mypic/pics/txt_cover.png",":/mypic/pics/pdf_cover.png",":/mypic/pics/epub_cover.png"};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mainwindowlist = new QList<QMainWindow*>;
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();
}

MainWindow::~MainWindow()
{
    delete drawmainpage,statusbar,currentbookcoverrect,threebookrect;
    drawmainpage = NULL;
//    pulldownwindow = NULL;
    statusbar = NULL;
    currentbookcoverrect = NULL;
    threebookrect = NULL;

}


void MainWindow::init()
{

    drawmainpage = new DrawMainPage;
//    pulldownwindow = new PullDownWindow(this);
//    settings = new Settings(this);
    bookshelf = new BookShelf(this);
    thirdapplication = new ThirdApplications(this);

    statusbar = new StatusBar(this);
    currentbookcoverrect = new QList<myQRect*>;
    threebookrect = new QList<myQRect*>;
    totaltemp = new QList<localDirectoryItem>;
    currentPagebooklist = new QList<localDirectoryItem>;

    initView();
    targetWidgetIndex =-1;
    unable_last =0;
    unable_next =0;
    initConnection();

    getBookDataFromDataBase();
}


void MainWindow::initView()
{

    rectlist = new QList<myQRect*>;

    for(int i=0;i<sizeof(mainapge_x);i++){
      myrect = new myQRect;
      myrect->rect.setX(mainapge_x[i]);
      myrect->rect.setY(mainpage_y[i]);
      myrect->rect.setWidth(mainpage_w[i]);
      myrect->rect.setHeight(mainpage_h[i]);
      myrect->isPressed = false;
      assignMacroDefinition(myrect,i);
//      myrect->xid = i;//只有这个界面中的控件的xid从0 至 20
      rectlist->append(myrect);
    }


}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    targetWidgetIndex = commonUtils::getTheTargetWidget(event->x(),event->y(),rectlist);
    if(targetWidgetIndex>-1){

        rectlist->at(targetWidgetIndex)->isPressed = true;
        this->repaint();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(targetWidgetIndex>-1){
//        rectflag[targetWidgetIndex] = 0;
//        rectlist->at(targetWidgetIndex).isPressed = false;
        switch (targetWidgetIndex) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            if(currentPageOfMainPage>1){

                endpage = false;
                firstpage = false;
                currentPageOfMainPage--;
                currentPagebooklist = commonUtils::getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);
                qDebug()<<"currentPagebooklist->size()==="<<currentPagebooklist->size();
            }else{

                firstpage = true;
                endpage = false;
            }
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            if(currentPageOfMainPage<totalPagesOfBooks-1){

                currentPageOfMainPage++;
                endpage = false;
                firstpage = false;
                currentPagebooklist = commonUtils::getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);
            }else{
                unable_next = 1;
                unable_last =0;
                endpage = true;
                firstpage = false;
            }
            threebookrect->clear();
            for(int i=0;i<currentPagebooklist->size();i++){
                threebookrect->append(rectlist->at(4+i));//4 is the index of rect in the layout.

            }

            break;
        case 8:
            if(bookshelf==NULL){
                bookshelf = new BookShelf(this);
            }
            bookshelf->show();
            break;
        case 9:
            if(thirdapplication==NULL){
                thirdapplication = new ThirdApplications(this);

            }
            thirdapplication->show();
            break;
        case 10:
//            if(settings==NULL){
//                settings = new Settings(this);
//            }
//            settings->show();
            break;
        case 11:
//            if(pulldownwindow==NULL){
//                pulldownwindow = new PullDownWindow(this);
//            }
//            pulldownwindow->show();
            break;
        default:
            break;
        }
        this->repaint();
        targetWidgetIndex = -1;
    }

}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    statusbar->drawSystemTime(painter,QString("15:30"));
    statusbar->drawWifiStatus(painter,true);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawBattery(painter,80);

     painter->drawRect(rectlist->at(HPM_LEFTBOOK_RECT)->rect);
     painter->drawRect(rectlist->at(HPM_RIGHTBOOK_RECT)->rect);





//    for(int i=0;i<21;i++){
//        painter->drawRect(rectlist->at(i)->rect);
//    }

//    //    QPainter *painter,QStringList bookCoverPath,QStringList booktitle,QList<QRect> rect)
//    currentbookcoverlist.append(cover_group[0]);
//    currentbookcoverlist.append(cover_group[1]);
//    currentbookcovertitle.append("");
//    currentbookcovertitle.append("");
//    currentbookcoverrect->append(rectlist->at(0));
//    currentbookcoverrect->append(rectlist->at(1));
//    drawmainpage->drawCurrentBookCover(painter,currentbookcoverlist,currentbookcovertitle,currentbookcoverrect);
//    drawmainpage->drawTextView(painter,rectlist->at(2),tr("NewB"));
//    drawmainpage->drawNextPage(painter,rectlist->at(7)->isPressed,rectlist->at(7),endpage);

//    drawmainpage->drawLastPage(painter,rectlist->at(3)->isPressed,rectlist->at(3),firstpage);

//    for(int i=0;i<currentPagebooklist->size();i++){
//        qDebug()<<"currentPagebooklist..."<<currentPagebooklist->at(i).file_name;
//    }
//    drawmainpage->drawThreeBooksArea(painter,threebookrect,currentPagebooklist);

//    drawmainpage->drawThreeModulesBottom1(painter,rectlist->at(8)->isPressed,rectlist->at(8));
//    drawmainpage->drawThreeModulesBottom2(painter,rectlist->at(9)->isPressed,rectlist->at(9));
//    drawmainpage->drawThreeModulesBottom3(painter,rectlist->at(10)->isPressed,rectlist->at(10));

}

void MainWindow::initConnection()
{


}

void MainWindow::assignMacroDefinition(myQRect *rect,int index)
{
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

}

void MainWindow::getBookDataFromDataBase()
{
    Database* tempdatabase = Database::getInstance();
    totaltemp =  tempdatabase->getLastTimeTableFromDatabase();
    int size = totaltemp->size();

    if(size>0){
        if(size%3==0){
            totalPagesOfBooks = size/3;
        }else{
            totalPagesOfBooks = size/3+1;
        }
        currentPageOfMainPage =1;
        if(totalPagesOfBooks>1){
            endpage = false;
            firstpage = true;
        }else{
            endpage = true;
        }


        currentPagebooklist = commonUtils::getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);

        threebookrect->clear();
        for(int i=0;i<currentPagebooklist->size();i++){
            threebookrect->append(rectlist->at(4+i));//4 is the index of rect in the layout.
        }

        //        qDebug()<<"totaltemp===="<<QString::number(totaltemp);
        qDebug()<<"currentPageOfMainPage===="<<currentPageOfMainPage;
        qDebug()<<"currentPagebooklist.size()==="<<currentPagebooklist->size();

    }


}
