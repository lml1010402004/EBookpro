#include "drawbookshelf.h"
#include<QFont>


const QString bookcity = ":/mypic/pics/bookcity.png";
const QString lastpath_pressed = ":/mypic/pics/back_pressed.png";
const QString lastpath_unpressed = ":/mypic/pics/back_unpressed.png";
const QString firstpath_pressed = ":/mypic/pics/firstpage_pressed.png";
const QString firstpath_unpress = ":/mypic/pics/firstpage_unpress.png";

const QString forwardpath_pressed = ":/mypic/pics/forward_pressed.png";
const QString forwardpath_unpressed = ":/mypic/pics/forward_unpressed.png";
const QString endpath_pressed = ":/mypic/pics/endpage_pressed.png";
const QString endpath_unpress = ":/mypic/pics/endpage_unpressed.png";

 QString home_pressed = ":/mypic/pics/home_pressed.png";
 QString home_unpress = ":/mypic/pics/home_unpress.png";

const QString circle_pressed = ":/mypic/pics/circlesfilled.png";
const QString circle_unpress = ":/mypic/pics/circlempty.png";
QString path4= ":/mypic/pics/bg3.png";

int position4[] = {66,180,165,180,120,140,66,180,300,180,150,25};


int position3[10] = {120,120,120,12,12,140,120,110,110,60};

DrawBookshelf::DrawBookshelf()
{

}

DrawBookshelf::~DrawBookshelf()
{

}

void DrawBookshelf::drawHomeButton(QPainter *painter,myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }

}

void DrawBookshelf::drawArrangeTextView(QPainter *painter,myQRect *rect, QString str)
{

    painter->drawText(rect->rect,str);
}

void DrawBookshelf::drawSelectedCondition(QPainter *painter, QList<ConditionItem> *conditionlist, int index)
{

    qDebug()<<"condition_selected_index==="<<index;
    int size = conditionlist->size();
   for(int i =0;i<size;i++){
      rect.setX(position3[0]+position3[1]*i);
      rect.setY(position3[2]);
      rect.setWidth(position3[3]);
      rect.setHeight(position3[4]);
      if(i==index-3){// because the index of rect is 3
      painter->drawPixmap(rect,circle_pressed);
      }else{
      painter->drawPixmap(rect,circle_unpress);
      }
      rect.setX(position3[5]+position3[6]*i);
      rect.setY(position3[7]);
      rect.setWidth(position3[8]);
      rect.setHeight(position3[9]);
      painter->drawText(rect,conditionlist->at(i).text_str);

   }
}



void DrawBookshelf::drawNineBooks(QPainter *painter, QList<localDirectoryItem> *booklist)
{
    QRect rect;
    QFont font;
    int size = booklist->size();
    int rows = 0;
    int columsoflastrow = size%3;
    if(size%3!=0){
        rows = size/3+1;
    }else{
        rows = size/3;
    }

    for(int i=0;i<rows;i++){
        if(i!=rows-1||columsoflastrow==0){
            for(int j=0;j<3;j++){
                rect.setX(position4[0]+position4[1]*j);
                rect.setY(position4[2]+position4[3]*i);
                rect.setWidth(position4[4]);
                rect.setHeight(position4[5]);
                painter->drawRect(rect);

                rect.setX(position4[0]+position4[1]*j+1);
                rect.setY(position4[2]+position4[3]*i+1);
                rect.setWidth(position4[4]-1);
                rect.setHeight(position4[5]-1);

                QString cover_path = booklist->at(i*3+j).file_path+".jpg";
                QFileInfo *info = new QFileInfo(cover_path);
                if(info->exists()){
                    painter->drawPixmap(rect,cover_path);
                }else{
                    painter->drawPixmap(rect,path4);
                }


                rect.setX(position4[6]+position4[7]*j-20);
                rect.setY(position4[8]+position4[9]*i+3);
                rect.setWidth(position4[10]);
                rect.setHeight(position4[11]);
                font.setPointSize(10);
                painter->setFont(font);
                QString str = booklist->at(i*3+j).file_name;
                if(str.length()>17){
                    str = str.mid(0,17).trimmed();
                }
                painter->drawText(rect,str);
            }

        }else{
            for(int k=0;k<columsoflastrow;k++){
                rect.setX(position4[0]+position4[1]*k);
                rect.setY(position4[2]+position4[3]*i);
                rect.setWidth(position4[4]);
                rect.setHeight(position4[5]);
                painter->drawRect(rect);

                rect.setX(position4[0]+position4[1]*k+1);
                rect.setY(position4[2]+position4[3]*i+1);
                rect.setWidth(position4[4]-1);
                rect.setHeight(position4[5]-1);

                QString cover_path = booklist->at(i*3+k).file_path+".jpg";
                QFileInfo *info = new QFileInfo(cover_path);
                if(info->exists()){
                    painter->drawPixmap(rect,cover_path);
                }else{
                    painter->drawPixmap(rect,path4);
                }
                rect.setX(position4[6]+position4[7]*k-20);
                rect.setY(position4[8]+position4[9]*i+3);
                rect.setWidth(position4[10]);
                rect.setHeight(position4[11]);
                font.setPointSize(10);
                painter->setFont(font);
                QString str = booklist->at(i*3+k).file_name;
                if(str.length()>17){
                    str = str.mid(0,17).trimmed();
                }
                painter->drawText(rect,str);
                //            painter->drawText(rect,booklist->at(i*3+k).file_name);
            }
        }

    }
}

void DrawBookshelf::drawTheFirstandLastPageIcon(QPainter *painter, myQRect *firstrect, myQRect *lastrect)
{
    if(firstrect->isPressed){
        painter->drawPixmap(firstrect->rect,firstpath_pressed);
    }else{
        painter->drawPixmap(firstrect->rect,firstpath_unpress);
    }
    if(lastrect->isPressed){
        painter->drawPixmap(lastrect->rect,lastpath_pressed);
    }else{
        painter->drawPixmap(lastrect->rect,lastpath_unpressed);
    }

}

void DrawBookshelf::drawTheNextandEndPageIcon(QPainter *painter, myQRect *nextrect, myQRect *endrect)
{

    if(nextrect->isPressed){
        painter->drawPixmap(nextrect->rect,forwardpath_pressed);
    }else{
        painter->drawPixmap(nextrect->rect,forwardpath_unpressed);
    }
    if(endrect->isPressed){
        painter->drawPixmap(endrect->rect,endpath_pressed);
    }else{
        painter->drawPixmap(endrect->rect,endpath_unpress);
    }
}

void DrawBookshelf::drawCurrentPageandTotalPages(QPainter *painter, int currentpage, int totalpages, myQRect *rect)
{
  painter->drawText(rect->rect,QString::number(currentpage)+"/"+QString::number(totalpages));
}
