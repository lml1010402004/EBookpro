#include "bookshelf.h"
#include"application.h"
#include"Utils/commonutils.h"
#include<QApplication>
#include"Application/rfile.h"


const int BOOKSHELF_X[12] = {400,500,40,120,260,380,500,130,200,270,360,430};
const int BOOKSHELF_Y[12] = {48,48,120,120,120,120,120,730,730,740,730,730};
const int BOOKSHELF_W[12] = {48,48,60,100,100,100,100,40,40,80,40,40};
const int BOOKSHELF_HE[12] = {48,48,40,40,40,40,40,40,40,40,40,40};


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

    rectlist = new QList<myQRect*>;
    for(int i =0;i<sizeof(BOOKSHELF_HE);i++){
        myrect = new myQRect;
        myrect->rect.setX(BOOKSHELF_X[i]);
        myrect->rect.setY(BOOKSHELF_Y[i]);
        myrect->rect.setWidth(BOOKSHELF_W[i]);
        myrect->rect.setHeight(BOOKSHELF_HE[i]);
        myrect->isPressed = false;
        RFIle::assignMacroDefinition(BOOK_SHELF_MODULE,myrect,i);
        rectlist->append(myrect);
    }

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

    drawbookshelf->drawHomeButton(painter,rectlist->at(BSM_HOME_BUTTON));
    QLineF line(0,100,600,100);
    painter->drawLine(line);

    qDebug()<<"currentpagebooklistinfolist==========="<<currentpagebookinfolist->size();
    drawbookshelf->drawNineBooks(painter,currentpagebookinfolist);
    drawbookshelf->drawCurrentPageandTotalPages(painter,current_page,total_pages,rectlist->at(BSM_PAGES_CONTENT));
//    drawbookshelf->drawArrangeTextView(painter,rectlist->at(BSM_TEXT),tr("Sort"));

//    drawbookshelf->drawTheFirstandLastPageIcon(painter,rectlist->at(BSM_FIRST_PAGE),rectlist->at(BSM_LAST_PAGE));

//    drawbookshelf->drawTheNextandEndPageIcon(painter,rectlist->at(BSM_NEXT_PAEG),rectlist->at(BSM_END_PAGE));

//    drawbookshelf->drawSelectedCondition(painter,conditonsItemlist,condition_selected_index);
}

void BookShelf::mousePressEvent(QMouseEvent *event)
{

        targetwidgetindex = commonUtils::getTheTargetWidget(event->x(),event->y(),rectlist);
        if(targetwidgetindex>-1){
            rectlist->at(targetwidgetindex)->isPressed = true;
            if(targetwidgetindex>5&&targetwidgetindex<10){
                condition_selected_index  = targetwidgetindex;
            }
            this->repaint();
        }
}

void BookShelf::mouseReleaseEvent(QMouseEvent *event)
{

    if(targetwidgetindex>-1){
       rectlist->at(targetwidgetindex)->isPressed = false;
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
