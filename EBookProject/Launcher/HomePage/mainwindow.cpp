#include "mainwindow.h"
#include"Application/application.h"
//#include<QDebug>
#include"Utils/commonutils.h"
#include<QBrush>
#include"Application/rfile.h"
#include"Application/pulldownwindow.h"


const int mainapge_x[21] = {100,350,100,350,160,410,270,40,90,240,390,520,120,270,420,70,270,470,80,280,480};
const int mainpage_y[21] = {110,110,200,200,330,330,450,530,480,480,480,530,640,640,640,700,700,700,770,770,770};
const int mainpage_w[21] = {150,150,150,150,60,60,60,40,120,120,120,40,80,80,80,64,64,64,60,60,60};
const int mainpage_h[21] = {200,200,40,40,20,20,30,40,150,150,150,40,20,20,20,64,64,64,20,20,20};


PulldownWindow *pulldownwindow;
int pulldownwindowrect[] = {250,0,100,60};

const QString homeiconpath = ":/mypic/pics/homeicon.png";

const QString nextpage_path = ":/mypic/pics/nextpage_rectangle.png";
const QString lastpage_path = ":/mypic/pics/lastpage_rectangle.png";
const QString unable_next_path=":/mypic/pics/unable_next.png";
const QString unable_last_path=":/mypic/pics/unable_last.png";

const QString booklibray_path=":/mypic/pics/book_library.png";
const QString bookcity = ":/mypic/pics/bookcity.png";
const QString gamepath = ":/mypic/pics/game.png";

QList<QMainWindow*> *mainwindowlist;
QProcess *myprocess;


const QString cover_group[3] = {":/mypic/pics/txt_cover.png",":/mypic/pics/pdf_cover.png",":/mypic/pics/epub_cover.png"};

const QString SETTING = "/usr/local/app/AppSettings";
const QString APP_WORKING_DIR = "/usr/local/app";

const QString MAINPAGE_BOOKSHELF = QObject::tr("Library");
const QString MAINPAGE_APPS = QObject::tr("Apps");
const QString MAINPAGE_SETTING = QObject::tr("Setting");



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
    for(int n =0;n<currentbookcoverrect->size();n++){
        delete currentbookcoverrect->at(n);

    }
    for(int l=0;l<rectlist->size();l++){
        delete rectlist->at(l);
    }

    delete drawmainpage,statusbar,currentbookcoverrect,threebookrect,myprocess,commonutils,
            currentbookcoverlist,bookshelf,totaltemp,currentPagebooklist,thirdapplication,rectlist;

    delete pulldownwindow;


}


void MainWindow::init()
{

    commonutils = new commonUtils;
    myprocess = new QProcess(this);
    drawmainpage = new DrawMainPage;
    pulldownwindow = new PulldownWindow(this);
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
    for(int i=0;i<21;i++){
        myrect = new myQRect;
        myrect->rect.setX(mainapge_x[i]);
        myrect->rect.setY(mainpage_y[i]);
        myrect->rect.setWidth(mainpage_w[i]);
        myrect->rect.setHeight(mainpage_h[i]);
        myrect->isPressed = false;
        RFIle::assignMacroDefinition(HOME_PAGE_MODULE,myrect,i);
        rectlist->append(myrect);
    }

}


void MainWindow::mousePressEvent(QMouseEvent *event)
{

    targetWidgetIndex = commonUtils::getTheTargetWidget(event->x(),event->y(),rectlist);
     qDebug()<<".........=="<<targetWidgetIndex;
    if(targetWidgetIndex>-1){
        rectlist->at(targetWidgetIndex)->isPressed = true;
        this->repaint();
    }else{
        if(event->x()>pulldownwindowrect[0]&&event->x()<(pulldownwindowrect[0]+pulldownwindowrect[2])&&
                event->y()<pulldownwindowrect[3]){
            if(pulldownwindow==NULL){
                pulldownwindow = new PulldownWindow(this);
            }
            pulldownwindow->show();
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(targetWidgetIndex>-1){
        rectlist->at(targetWidgetIndex)->isPressed = false;
        switch (targetWidgetIndex) {
        case HPM_LEFTBOOK_RECT:

            break;
        case HPM_RIGHTBOOK_RECT:
            break;
        case HPM_LASTPAGE_BUTTON:
            if(currentPageOfMainPage>1){
                endpage = false;
                firstpage = false;
                currentPageOfMainPage--;
                currentPagebooklist = commonUtils::getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);

            }else{
                firstpage = true;
                endpage = false;
            }
            break;
        case HPM_FIRSTBOOK_RECT:          
            if(currentPagebooklist->size()>0){

             commonutils->openBookFromFBreader(myprocess,currentPagebooklist->at(0).file_path);
            }
            break;
        case HPM_SECONDBOOK_RECT:
            if(currentPagebooklist->size()>1){

             commonutils->openBookFromFBreader(myprocess,currentPagebooklist->at(1).file_path);
            }
            break;
        case HPM_THIRDBOOK_RECT:
            if(currentPagebooklist->size()>2){
             commonutils->openBookFromFBreader(myprocess,currentPagebooklist->at(2).file_path);
            }
            break;
        case HPM_NEXTPAGE_BUTTON:
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
            assignDynamicRectstoThreerect(currentPagebooklist->size());
            break;
        case HPM_BOOKSHELF_BUTTON:
            if(bookshelf==NULL){
                bookshelf = new BookShelf(this);
            }
            bookshelf->show();

            break;
        case HPM_APP_BUTTON:
            if(thirdapplication==NULL){
                thirdapplication = new ThirdApplications(this);
            }
            thirdapplication->show();
            break;
        case HPM_SETTING_BUTTON:
            commonutils->openSettingApp(myprocess,"/usr/local/app/AppSettings");
            break;
        default:
            break;
        }
        targetWidgetIndex = -1;
        this->repaint();
    }

}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    statusbar->drawSystemTime(painter,QString("15:30"));
    statusbar->drawWifiStatus(painter,true);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawBattery(painter,80);

    //    QPainter *painter,QStringList bookCoverPath,QStringList booktitle,QList<QRect> rect)
    currentbookcoverlist.append(cover_group[0]);
    currentbookcoverlist.append(cover_group[1]);
    currentbookcovertitle.append("");
    currentbookcovertitle.append("");
    currentbookcoverrect->append(rectlist->at(HPM_LEFTBOOK_RECT));
    currentbookcoverrect->append(rectlist->at(HPM_RIGHTBOOK_RECT));
    drawmainpage->drawCurrentBookCover(painter,currentbookcoverlist,currentbookcovertitle,currentbookcoverrect);
    drawmainpage->drawTextView(painter,rectlist->at(HPM_NEW_BOOK),tr("NewBook"));
    drawmainpage->drawNextPage(painter,rectlist->at(HPM_NEXTPAGE_BUTTON),endpage);

    drawmainpage->drawLastPage(painter,rectlist->at(HPM_LASTPAGE_BUTTON),firstpage);


    drawmainpage->drawThreeBooksArea(painter,threebookrect,currentPagebooklist);

    drawmainpage->drawThreeModulesBottom1(painter,rectlist->at(HPM_BOOKSHELF_BUTTON),MAINPAGE_BOOKSHELF);
    drawmainpage->drawThreeModulesBottom2(painter,rectlist->at(HPM_APP_BUTTON),MAINPAGE_APPS);
    drawmainpage->drawThreeModulesBottom3(painter,rectlist->at(HPM_SETTING_BUTTON),MAINPAGE_SETTING);

}

void MainWindow::initConnection()
{
 QObject::connect(myprocess,SIGNAL(finished(int ,QProcess::ExitStatus)),this,SLOT(processFinished(int)));
}


void MainWindow::assignDynamicRectstoThreerect(int i)
{

    switch (i) {
    case 0:
        break;
    case 1:
        threebookrect->append(rectlist->at(HPM_FIRSTBOOK_RECT));
        break;
    case 2:
        threebookrect->append(rectlist->at(HPM_FIRSTBOOK_RECT));
        threebookrect->append(rectlist->at(HPM_SECONDBOOK_RECT));
        break;
    case 3:
        threebookrect->append(rectlist->at(HPM_FIRSTBOOK_RECT));
        threebookrect->append(rectlist->at(HPM_SECONDBOOK_RECT));
        threebookrect->append(rectlist->at(HPM_THIRDBOOK_RECT));
        break;
    default:
        break;
    }


}

void MainWindow::processFinished(int value)
{
  if(value==0){
      qDebug()<<"hello Setting quit successfully!!!";
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
        assignDynamicRectstoThreerect(currentPagebooklist->size());

    }


}


