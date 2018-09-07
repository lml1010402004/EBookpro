#include "bookshelf.h"
#include"application.h"
#include"Utils/commonutils.h"
#include<QApplication>


const int bookshelf1[4] = {500,48,48,48};
const int bookshelf2_x[] = {130,200,360,430};
const int bookshelf3_y=730;
const int bookshelf4_width = 40;
const int bookshelf5_height = 40;

const int arrangetext[4] = {30,120,100,50};

const int conditionlist_x[4] = {140,260,380,500};
const int conditionlist_y = 120;
const int conditionlist_width = 120;
const int condition_height= 60;

const int pagesrect[4]={285,740,60,40};


int bookshelf_rectflag[5] = {0,0,0,0,0};
QString emptypath = ":/mypic/pics/circlempty";


BookShelf::BookShelf(QWidget *parent) : QMainWindow(parent)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();

}

BookShelf::~BookShelf()
{
    delete drawbookshelf,statusbar,conditonsItemlist,totalbookinfolist,currentpagebookinfolist,list,conditionitem;
    drawbookshelf = NULL;
    statusbar = NULL;
    conditonsItemlist = NULL;
    totalbookinfolist = NULL;
    currentpagebookinfolist = NULL;

}

void BookShelf::init(){
    drawbookshelf = new DrawBookshelf;
    statusbar = new StatusBar(this);
    condition_selected_index = 6;

    conditonsItemlist = new QList<ConditionItem>;
    totalbookinfolist = new QList<localDirectoryItem>;
    currentpagebookinfolist = new QList<localDirectoryItem>;


    list.clear();
    list.append(tr("Read"));
    list.append(QObject::tr("Name"));
    list.append(QObject::tr("Time"));
    list.append(QObject::tr("Author"));
    for(int i=0;i<list.size();i++){
        conditionitem.setCircle_icon_path(emptypath);
        conditionitem.setText_str(list.at(i));
        conditonsItemlist->append(conditionitem);
    }

    totalbookinfolist = Database::getInstance()->getAllDataFromTouchedTable();


    total_pages = getTotalPagesForEachCondition(totalbookinfolist);
    if(total_pages>0){
        current_page = 1;
        currentpagebookinfolist =  getCurrentPageBooklist(totalbookinfolist,current_page);
    }else{
        current_page =0;
    }

    initView();
    initConnection();
}

void BookShelf::initView(){

    //here we should get the 9 widgets position as follows.
    rectlist = new QList<QRect>;

    rect.setX(bookshelf1[0]);
    rect.setY(bookshelf1[1]);
    rect.setWidth(bookshelf1[2]);
    rect.setHeight(bookshelf1[3]);
    rectlist->append(rect);//home icon index =0

    rect.setX(bookshelf2_x[0]);
    rect.setY(bookshelf3_y);
    rect.setWidth(bookshelf4_width);
    rect.setHeight(bookshelf5_height);
    rectlist->append(rect); //First page index =1;

    rect.setX(bookshelf2_x[1]);
    rect.setY(bookshelf3_y);
    rect.setWidth(bookshelf4_width);
    rect.setHeight(bookshelf5_height);
    rectlist->append(rect);//Last page index =2

    rect.setX(bookshelf2_x[2]);
    rect.setY(bookshelf3_y);
    rect.setWidth(bookshelf4_width);
    rect.setHeight(bookshelf5_height);
    rectlist->append(rect);//next page index =3

    rect.setX(bookshelf2_x[3]);
    rect.setY(bookshelf3_y);
    rect.setWidth(bookshelf4_width);
    rect.setHeight(bookshelf5_height);
    rectlist->append(rect); //end page index = 4

    rect.setX(arrangetext[0]);
    rect.setY(arrangetext[1]);
    rect.setWidth(arrangetext[2]);
    rect.setHeight(arrangetext[3]);
    rectlist->append(rect);//排序文字 index=5

    rect.setX(conditionlist_x[0]);
    rect.setY(conditionlist_y);
    rect.setWidth(conditionlist_width);
    rect.setHeight(condition_height);
    rectlist->append(rect);//order read index =6

    rect.setX(conditionlist_x[1]);
    rect.setY(conditionlist_y);
    rect.setWidth(conditionlist_width);
    rect.setHeight(condition_height);
    rectlist->append(rect);//book name index =7;

    rect.setX(conditionlist_x[2]);
    rect.setY(conditionlist_y);
    rect.setWidth(conditionlist_width);
    rect.setHeight(condition_height);
    rectlist->append(rect);//time index =8;

    rect.setX(conditionlist_x[3]);
    rect.setY(conditionlist_y);
    rect.setWidth(conditionlist_width);
    rect.setHeight(condition_height);
    rectlist->append(rect);//author index =9

    rect.setX(pagesrect[0]);
    rect.setY(pagesrect[1]);
    rect.setWidth(pagesrect[2]);
    rect.setHeight(pagesrect[3]);
    rectlist->append(rect);//pages index =10

}

void BookShelf::initConnection(){
   QObject::connect(this,SIGNAL(updateDataSignal()),this,SLOT(updateDataSlot()));
}

void BookShelf::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,100);
    statusbar->drawWifiStatus(painter,true);
    statusbar->drawSystemTime(painter,QString("15:30"));
    statusbar->drawPullDownRectangle(painter);

    drawbookshelf->drawHomeButton(painter,rectlist->at(0),bookshelf_rectflag[0]);
    QLineF line(0,100,600,100);
    painter->drawLine(line);

    qDebug()<<"currentpagebooklistinfolist==========="<<currentpagebookinfolist->size();
    drawbookshelf->drawNineBooks(painter,currentpagebookinfolist);
    drawbookshelf->drawCurrentPageandTotalPages(painter,current_page,total_pages,rectlist->at(10));
    drawbookshelf->drawArrangeTextView(painter,rectlist->at(5),tr("Sort"));

    drawbookshelf->drawTheFirstandLastPageIcon(painter,rectlist->at(1),bookshelf_rectflag[1],rectlist->at(2),bookshelf_rectflag[2]);

    drawbookshelf->drawTheNextandEndPageIcon(painter,rectlist->at(3),bookshelf_rectflag[3],rectlist->at(4),bookshelf_rectflag[4]);

    drawbookshelf->drawSelectedCondition(painter,conditonsItemlist,condition_selected_index);
}

void BookShelf::mousePressEvent(QMouseEvent *event)
{

//    targetwidgetindex = commonUtils::getTheTargetWidget(event->x(),event->y(),rectlist);
//    if(targetwidgetindex>-1){
//        bookshelf_rectflag[targetwidgetindex] = 1;
//        if(targetwidgetindex>5&&targetwidgetindex<10){
//            condition_selected_index  = targetwidgetindex;
//        }
//        this->repaint();
//    }
}

void BookShelf::mouseReleaseEvent(QMouseEvent *event)
{

    if(targetwidgetindex>-1){
        bookshelf_rectflag[targetwidgetindex] =0;
        switch (targetwidgetindex){
        case 0:
            this->close();
            break;
        case 1:
            current_page = 1;
            emit updateDataSignal();

            break;
        case 2:
            if(current_page>1){
                current_page--;
                emit updateDataSignal();
            }
            break;
        case 3:
            if(current_page<total_pages){
                current_page++;
                emit updateDataSignal();
            }
            break;
        case 4:
            current_page = total_pages;
            emit updateDataSignal();
            break;
        case 5:
            break;
        case 6:
            current_page =1;
            emit updateDataSignal();
            break;
        case 7:
             current_page =1;
            emit updateDataSignal();
            break;
        case 8:
             current_page =1;
            emit updateDataSignal();
            break;
        case 9:
             current_page =1;
            emit updateDataSignal();
            break;

        default:
            break;
        }
        this->repaint();
        targetwidgetindex = -1;


    }

}

void BookShelf::mouseMoveEvent(QMouseEvent *event)
{

}

int BookShelf::getTheTargetBookIndex(int x_pos, int y_pos)
{
    int temp = -1;

    return temp;

}

int BookShelf::getTotalPagesForEachCondition(QList<localDirectoryItem> *list){

    int temp =0;
    qDebug()<<"list.size()=="<<list->size();
    if(list->size()%9==0){
        temp = list->size()/9;
    }else{
        temp = list->size()/9+1;
    }

    qDebug()<<"totalpages--temp=="<<temp;
    return temp;
}


QList<localDirectoryItem>* BookShelf::getCurrentPageBooklist(QList<localDirectoryItem> *list, int currentpage){
    QList<localDirectoryItem> *temp = new QList<localDirectoryItem>;
    temp = commonUtils::getCurrentPageBooks(list,currentpage,9);
    return temp;
}

void BookShelf::processFinisheds(){
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);//刷新
    this->repaint();
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);//刷新
    repaint();
}

void BookShelf::updateDataSlot(){
   totalbookinfolist->clear();
   switch (condition_selected_index) {
   case 6:
       totalbookinfolist = Database::getInstance()->getAllDataFromTouchedTable();
       total_pages = getTotalPagesForEachCondition(totalbookinfolist);
       break;
   case 7:
       totalbookinfolist = Database::getInstance()->getAllDataFromTotalBooklistTable("name");
       total_pages = getTotalPagesForEachCondition(totalbookinfolist);
       break;
   case 8:
       totalbookinfolist = Database::getInstance()->getAllDataFromTotalBooklistTable("xid");
       total_pages = getTotalPagesForEachCondition(totalbookinfolist);
       break;
   case 9:
       totalbookinfolist = Database::getInstance()->getAllDataFromTotalBooklistTable("author");
       total_pages = getTotalPagesForEachCondition(totalbookinfolist);
       break;
   default:
       break;
   }
    currentpagebookinfolist = commonUtils::getCurrentPageBooks(totalbookinfolist,current_page,9);
    this->repaint();

}
