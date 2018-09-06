#include "drawmainpage.h"
#include<QDebug>
#include<QFileInfo>
#include<QFile>


const QString homepressed = ":/mypic/pics/home_pressed.png";
const QString homeunpressed = ":/mypic/pics/homeicon.png";
const QString lastpageunpressed = ":/mypic/pics/back_unpressed.png";
const QString nextpagepressed=":/mypic/pics/forward_pressed.png";
const QString lastpagepressed=":/mypic/pics/back_pressed.png";
const QString nextpageunpressed=":/mypic/pics/forward_unpressed.png";


const QString bookshelf=":/mypic/pics/bookshelf.png";
const QString application=":/mypic/pics/application.png";
const QString setting = ":/mypic/pics/setting.png";

const QString bookshelf_pressed=":/mypic/pics/bookshelf_pressed.png";
const QString application_pressed=":/mypic/pics/application_pressed.png";
const QString setting_pressed=":/mypic/pics/setting_pressed.png";


//const QString txt_cover = ":/mypic/pics/pdf_cover.png";



DrawMainPage::DrawMainPage()
{

}

DrawMainPage::~DrawMainPage()
{

}


void DrawMainPage::drawCurrentBookCover(QPainter *painter,QStringList bookCoverPath,QStringList booktitle,QList<QRect> *rect)
{
    QRect temprect;
    temprect.setX(rect->at(0).x()-1);
    temprect.setY(rect->at(0).y()-1);
    temprect.setWidth(rect->at(0).width()+1);
    temprect.setHeight(rect->at(0).height()+1);
    painter->drawRect(temprect);
    painter->drawPixmap(rect->at(0),bookCoverPath.at(0));
    if(booktitle.at(0).length()>0){

    }

    temprect.setX(rect->at(1).x()-1);
    temprect.setY(rect->at(1).y()-1);
    temprect.setWidth(rect->at(1).width()+1);
    temprect.setHeight(rect->at(1).height()+1);
    painter->drawRect(temprect);
    painter->drawPixmap(rect->at(1),bookCoverPath.at(1));
    if(booktitle.at(1).length()>0){

    }






}

void DrawMainPage::drawCurrentBookAuthor(QPainter *painter, QString bookAuthor, QRect rect)
{
    painter->drawText(rect,bookAuthor);
}


void DrawMainPage::drawCurrentBookProgress(QPainter *painter, int percentage, QRect rect)
{
    painter->drawText(rect,QString::number(percentage));
}

void DrawMainPage::drawLastPage(QPainter *painter, int index, QRect rect,bool firstpage)
{
    if(!firstpage){
        if(index==0){
            painter->drawPixmap(rect,lastpageunpressed);
        }else if(index==1){
            painter->drawPixmap(rect,lastpagepressed);
        }
    }

}

void DrawMainPage::drawNextPage(QPainter *painter, int index, QRect rect,bool endpage)
{
    if(!endpage){
        if(index==0){
            painter->drawPixmap(rect,nextpageunpressed);
        }else if(index==1){
            painter->drawPixmap(rect,nextpagepressed);
        }
    }
}

void DrawMainPage::drawTextView(QPainter *painter,QRect rect,QString title)
{
    font.setPixelSize(22);
    painter->setFont(font);
    painter->drawText(rect,title);

}

void DrawMainPage::drawThreeModulesBottom1(QPainter *painter, int index, QRect rect)
{
    if(index==1){
        painter->drawPixmap(rect,bookshelf_pressed);
    }else{
        painter->drawPixmap(rect,bookshelf);
    }

}

void DrawMainPage::drawThreeModulesBottom2(QPainter *painter, int index, QRect rect)
{
    if(index==1){
        painter->drawPixmap(rect,application_pressed);
    }else{
        painter->drawPixmap(rect,application);
    }

}

void DrawMainPage::drawThreeModulesBottom3(QPainter *painter, int index, QRect rect)
{
    if(index==1){
        painter->drawPixmap(rect,setting_pressed);
    }else{
        painter->drawPixmap(rect,setting);
    }

}

void DrawMainPage::drawThreeBooksArea(QPainter *painter, QList<QRect> *rectlist, QList<localDirectoryItem> *booklist)
{

    QRect rect;
    for(int i=0;i<rectlist->size();i++){
        rect.setX(rectlist->at(i).x()-1);
        rect.setY(rectlist->at(i).y()-1);
        rect.setWidth(rectlist->at(i).width()+1);
        rect.setHeight(rectlist->at(i).height()+1);
        painter->drawRect(rect);


        localDirectoryItem item = booklist->at(i);
        QString temppath ;
        QFile *tempFile = new QFile(item.file_path+".jpg");
        if(tempFile->exists()==false){
            temppath =":/mypic/pics/bg2.png";
        }else{
            temppath = item.file_path+".jpg";
        }
        painter->drawPixmap(rect,temppath);

    }
}
