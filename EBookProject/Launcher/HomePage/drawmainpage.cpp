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


void DrawMainPage::drawCurrentBookCover(QPainter *painter,QStringList bookCoverPath,QStringList booktitle,QList<myQRect*> *rect)
{
    QRect temprect;
    temprect.setX(rect->at(0)->rect.x()-1);
    temprect.setY(rect->at(0)->rect.y()-1);
    temprect.setWidth(rect->at(0)->rect.width()+1);
    temprect.setHeight(rect->at(0)->rect.height()+1);
    painter->drawRect(temprect);
    painter->drawPixmap(rect->at(0)->rect,bookCoverPath.at(0));
    if(booktitle.at(0).length()>0){
        QRect temprect;
        temprect.setX(rect->at(0)->rect.x());
        temprect.setY(rect->at(0)->rect.y()+200);
        temprect.setWidth(rect->at(0)->rect.width());
        temprect.setHeight(rect->at(0)->rect.height()-170);
       painter->drawText(temprect,booktitle.at(0).split(".").at(0)+"..");
    }

    temprect.setX(rect->at(1)->rect.x()-1);
    temprect.setY(rect->at(1)->rect.y()-1);
    temprect.setWidth(rect->at(1)->rect.width()+1);
    temprect.setHeight(rect->at(1)->rect.height()+1);
    painter->drawRect(temprect);
    painter->drawPixmap(rect->at(1)->rect,bookCoverPath.at(1));
    if(booktitle.at(1).length()>0){
      QRect temprect;
      temprect.setX(rect->at(1)->rect.x());
      temprect.setY(rect->at(1)->rect.y()+200);
      temprect.setWidth(rect->at(1)->rect.width());
      temprect.setHeight(rect->at(1)->rect.height()-170);
     painter->drawText(temprect,booktitle.at(1).split(".").at(0)+"..");
    }


}

void DrawMainPage::drawCurrentBookAuthor(QPainter *painter, QString bookAuthor, myQRect* rect)
{
    painter->drawText(rect->rect,bookAuthor);
}


void DrawMainPage::drawCurrentBookProgress(QPainter *painter, int percentage, myQRect* rect)
{
    painter->drawText(rect->rect,QString::number(percentage));
}

void DrawMainPage::drawLastPage(QPainter *painter, myQRect* rect,bool firstpage)
{
    if(!firstpage){
        if(!rect->isPressed){
            painter->drawPixmap(rect->rect,lastpageunpressed);
        }else{
            painter->drawPixmap(rect->rect,lastpagepressed);
        }
    }

}

void DrawMainPage::drawNextPage(QPainter *painter, myQRect* rect,bool endpage)
{
    if(!endpage){
        if(!rect->isPressed){
            painter->drawPixmap(rect->rect,nextpageunpressed);
        }else{
            painter->drawPixmap(rect->rect,nextpagepressed);
        }
    }
}

void DrawMainPage::drawTextView(QPainter *painter,myQRect* rect,QString title)
{
    font.setPixelSize(22);
    painter->setFont(font);
    painter->drawText(rect->rect,title);

}

void DrawMainPage::drawThreeModulesBottom1(QPainter *painter, myQRect* rect,QString title)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,bookshelf_pressed);
    }else{
        painter->drawPixmap(rect->rect,bookshelf);
    }
    QRect temprect;
    temprect.setX(rect->rect.x());
    temprect.setY(rect->rect.y()+60);
    temprect.setWidth(rect->rect.width()+10);
    temprect.setHeight(rect->rect.height()-30);
    painter->drawText(temprect,title);



}

void DrawMainPage::drawThreeModulesBottom2(QPainter *painter, myQRect* rect,QString title)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,application_pressed);
    }else{
        painter->drawPixmap(rect->rect,application);
    }
    QRect temprect;
    temprect.setX(rect->rect.x());
    temprect.setY(rect->rect.y()+60);
    temprect.setWidth(rect->rect.width()+10);
    temprect.setHeight(rect->rect.height()-30);
    painter->drawText(temprect,title);


}

void DrawMainPage::drawThreeModulesBottom3(QPainter *painter, myQRect* rect,QString title)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,setting_pressed);
    }else{
        painter->drawPixmap(rect->rect,setting);
    }
    QRect temprect;
    temprect.setX(rect->rect.x());
    temprect.setY(rect->rect.y()+60);
    temprect.setWidth(rect->rect.width()+10);
    temprect.setHeight(rect->rect.height()-30);
    painter->drawText(temprect,title);

}

void DrawMainPage::drawThreeBooksArea(QPainter *painter, QList<myQRect*> *rectlist, QList<localDirectoryItem> *booklist)
{

    QRect rect;
    for(int i=0;i<rectlist->size();i++){
        rect.setX(rectlist->at(i)->rect.x()-1);
        rect.setY(rectlist->at(i)->rect.y()-1);
        rect.setWidth(rectlist->at(i)->rect.width()+1);
        rect.setHeight(rectlist->at(i)->rect.height()+1);
        painter->drawRect(rect);

        rect.setX(rectlist->at(i)->rect.x());
        rect.setY(rectlist->at(i)->rect.y());
        rect.setWidth(rectlist->at(i)->rect.width());
        rect.setHeight(rectlist->at(i)->rect.height());
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
        QRect tempremp;
        tempremp.setX(rect.x()-8);
        tempremp.setY(rect.y()+rect.height()+2);
        tempremp.setWidth(rect.width()+10);
        tempremp.setHeight(30);
        QString str = booklist->at(i).file_name;
        if(str.length()>20){
            str = str.mid(0,14)+"..";

        }
        painter->drawText(tempremp,str+"..");

    }
}
