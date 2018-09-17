#include "database.h"
#include<QDebug>

const QString DATABASEPATH="/usr/local/app/";


const QString CREATEUNTOUCHEDTABLE = "create table untouchedbooklist(xid INTEGER primary key,name varchar(40),cover_path varchar(160),progress INTEGER,mark INTEGER)";
const QString CREATETOUCHEDTABLE = "create table touchedbooklist(xid INTEGER primary key,name varchar(40),cover_path varchar(160),progress INTEGER, mark INTEGER ,cov_exsit BLOB)";
const QString CREATETOTALBOOKSTABLE="create table totalbooks(xid INTEGER primary key,name varchar(40),cover_path varchar(160),progress INTEGER,mark INTEGER,author varchar(40))";
const QString CREATELASTTIMETABLE="create table lasttimebooks(xid INTEGER primary key,name varchar(40),cover_path varchar(160))";

const QString INSERTBOOKINTOUNTOUCHEDTABLE =  "insert into untouchedbooklist values(?,?,?,?,?)";
const QString INSERTINTOTOTAL="insert into totalbooks values(?,?,?,?,?,?)";
const QString INSERTBOOKINTOLASTTIMETABLE="insert into lasttimebooks values(?,?,?)";
const QString INSERTADATATOTOUCHEDBOOKTABLE = "insert into touchedbooklist values(?,?,?,?,?,?)";

const QString DELETETARGETXIDFROMUNTOUCHEDTABLE = "delete from untouchedbooklist where xid = ?";
const QString SELECTFROMUNTOUCHEDTABLE="select * from untouchedbooklist where cover_path=?";


const QString SELECTMAXIDTOUCHEDTABLE = "select max(xid) from touchedbooklist";
const QString SELECTMAXIDUNTOUCHEDTABLE ="select max(xid) from untouchedbooklist";
const QString SELECTFILENAMEFROMTOUCHEDBOOKLIST = "select name,cover_path from touchedbooklist";
const QString SELECTFILENAMEFROMUNTOUCHEDBOOKLIST="select name,cover_path from untouchedbooklist";
const QString SELECTALLFROMLASTTIMETABLE="select * from lasttimebooks";
const QString SELECTALLFROMTOTALBOOKSTABLEBYBOOKNAME = "select * from totalbooks order by ?";
const QString SELECTALLFROMTOTALBOOKSTABLELIKENAME = "select * from totalbooks where name like ?";




const QString SELECTDATAFROMTOUCHEDTABLE="select * from touchedbooklist";

const QString TRUNCATEALLDATAFROMLASTTIMETABLE="delete from lasttimebooks";



QList<localDirectoryItem> filelist;//this variable need be emptyed by settingusbtransfer.So difine it as a globle variable.

QString path3 = ":/mypic/pics/bg2.png";



static Database *m_pInstance;


Database::Database()
{
    QFile file(DATABASEPATH+"yitoabook.db");
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(DATABASEPATH+"yitoabook.db");
    if(!file.exists()){
        QSqlQuery myQuery(database);
       if(database.open()){
           qDebug()<<"database open already!!!";
           myQuery.prepare(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("touchedbooklist"));
           bool isTableExist = myQuery.exec();
           if(!isTableExist){
                qDebug()<<"create table already!!!";
              createBooksTable(myQuery);
           }
       }else{
           bool flag = openDataBase();
           qDebug()<<"open dataBase successfully!!!";
       }

    }else{

bool falg = openDataBase();

    }

}

Database::~Database()
{

}



/**
 * @brief operateDatabase::createBooksTable
 * @param query
 * @return
 */
bool Database::createBooksTable(QSqlQuery query)
{
    qDebug()<<"create tables already!!!";
  query.prepare(CREATEUNTOUCHEDTABLE);
  if(!query.exec()){
      qDebug()<<query.lastError();
  }else{
      qDebug()<<"create untouched table successfully!!";
  }
  query.prepare(CREATETOUCHEDTABLE);
  if(!query.exec()){
      qDebug()<<query.lastError();
  }else {
      qDebug()<<"create touched table successfully!!!";
  }
  query.prepare(CREATELASTTIMETABLE);
  if(!query.exec()){
      qDebug()<<query.lastError();
  }else{
      qDebug()<<"create lasttime table successfuly";
  }
  query.prepare(CREATETOTALBOOKSTABLE);
  if(!query.exec()){
      qDebug()<<query.lastError();
  }else{
      qDebug()<<"crate totalbooks successfyll";
  }


}

bool Database::insertBookDataUntouched(localDirectoryItem item)
{

    bool flag = false;
    if(openDataBase()){
            QSqlQuery query(database);
            query.prepare(INSERTBOOKINTOUNTOUCHEDTABLE);
            query.addBindValue(item.xid);
            query.addBindValue(item.file_name);
            query.addBindValue(item.file_path);
            query.addBindValue(item.progress);
            query.addBindValue(item.file_type);
            if(query.exec()){
                flag = true;
            }else {
                qDebug()<<"insert into databse fail...."<<query.lastError();
            }
    }
    return flag;


}

/**
 * @brief Database::insertIntoLastTimeTable
 * @param item
 * @return
 */
bool Database::insertIntoLastTimeTable(localDirectoryItem item)
{
    bool flag = false;
    if(openDataBase()){
      QSqlQuery query(database);

      query.prepare(INSERTBOOKINTOLASTTIMETABLE);
      query.addBindValue(item.xid);
      query.addBindValue(item.file_name);
      query.addBindValue(item.file_path);
       if(query.exec()){
           flag =true;
       }else{
           qDebug()<<"insert into database fail..."<<query.lastError();
       }

    }
return flag;
}

/**
 * @brief Database::inserIntoTotaltable
 * @param item
 * @return
 */
bool Database::inserIntoTotaltable(localDirectoryItem item)
{
   bool flag = false;
   if(openDataBase()){
           QSqlQuery query(database);
           query.prepare(INSERTINTOTOTAL);
           query.addBindValue(item.xid);
           query.addBindValue(item.file_name);
           query.addBindValue(item.file_path);
           query.addBindValue(item.progress);
           query.addBindValue(item.file_type);
           query.addBindValue(item.file_name.split(".")[0]);
           if(query.exec()){
               flag = true;
           }else {
               qDebug()<<"insert into databse fail...."<<query.lastError();
           }
   }
   return flag;
}


/**
 * @brief Database::deleteADataFromUntouchedTable
 * @param xid
 * @return
 */
bool Database::deleteADataFromUntouchedTable(localDirectoryItem item)
{

  bool flag = false;
  if(openDataBase()){
      QSqlQuery query(database);
      query.prepare(SELECTFROMUNTOUCHEDTABLE);
      query.addBindValue(item.file_path);
          if(query.exec()){
              qDebug()<<"this data exist in untouchedtable";
          query.prepare(DELETETARGETXIDFROMUNTOUCHEDTABLE);
          query.addBindValue(item.xid);
          if(query.exec()){
              qDebug()<<"insert into successfully";
              flag =true;
          }else{
              qDebug()<<query.lastError();
          }
      }else{
              return false;
          }
  }
   return flag;
}


/**
 * @brief Database::inserADataToTouchedTable
 * @param item
 * @return
 */
bool Database::insertADataToTouchedTable(localDirectoryItem item)
{
 bool flag = false;
  if(openDataBase()){
     QSqlQuery query(database);
    query.prepare(INSERTADATATOTOUCHEDBOOKTABLE);
    query.addBindValue(item.xid);
    query.addBindValue(item.file_name);
    query.addBindValue(item.file_path);
    query.addBindValue(item.progress);
    query.addBindValue(item.file_type);
    query.addBindValue(item.cover_exist);
    if(query.exec()){
        qDebug()<<"insert into successfully";
        flag = true;
    }else{
        qDebug()<<query.lastError();
    }
  }

 return flag;

}

bool Database::databaseHasTheTargetData(localDirectoryItem item)
{

    for(int i=0;i<allRecordIntheDataBase().length();i++){
        if(allRecordIntheDataBase().at(i).file_path.compare(item.file_path)==0){
            qDebug()<<"this data should be inserted into database...!";
                return true;
            }
       }
        return false;

}

QList<localDirectoryItem> Database::getAllFileInTheTargetDirectory(QString directory)
{
    //    filelist.clear();
      QFileInfoList tempList;
      QDir rootDir(directory);
      tempList = rootDir.entryInfoList();
      qDebug()<<"templist......";
      qDebug()<<"templist......";
      qDebug()<<"templist......";
      qDebug()<<"templist......";
      for(int i =0;i<tempList.length();i++){
          if(tempList.at(i).fileName()=="."||tempList.at(i).fileName()==".."){
              continue;
          }
          if(tempList.at(i).isDir()){
              getAllFileInTheTargetDirectory(tempList.at(i).absoluteFilePath());
          }else{
//              if(tempList.at(i).suffix()=="txt"||tempList.at(i).suffix()=="epub"||tempList.at(i).suffix()=="pdf"||
//                      tempList.at(i).suffix()=="fb2"||tempList.at(i).suffix()=="rtf"||tempList.at(i).suffix()=="mobi"||
//                      tempList.at(i).suffix()=="chm"||tempList.at(i).suffix()=="djvu"||tempList.at(i).suffix()=="lit"||
//                      tempList.at(i).suffix()=="epub3")
              if(tempList.at(i).suffix()!="")
              {
                 tempItem.file_name = tempList.at(i).fileName();
                 tempItem.file_path = tempList.at(i).filePath();
                 if(tempList.at(i).suffix()=="txt"){
                     tempItem.file_type = 0;
                 }else if(tempList.at(i).suffix()=="epub"){
                     tempItem.file_type = 1;
                 }else if(tempList.at(i).suffix()=="pdf"){
                     tempItem.file_type = 2;
                 }else {
                     tempItem.file_type = 3;
                 }

                filelist.append(tempItem);

              }
          }

      }
    return filelist;

}

QList<localDirectoryItem> Database::allRecordIntheDataBase()
{

    QList<localDirectoryItem> tempList;
 if(openDataBase()){
            QSqlQuery query(database);
            query.prepare(SELECTFILENAMEFROMTOUCHEDBOOKLIST);
            if(query.exec()){

                while(query.next()){

                   tempItem.file_name = query.value(0).toString();
                   tempItem.file_path = query.value(1).toString();
                   tempList.append(tempItem);
                }
            }else{
                qDebug()<<query.lastError();
            }

            query.prepare(SELECTFILENAMEFROMUNTOUCHEDBOOKLIST);

            if(query.exec()){
                while(query.next()){

                    tempItem.file_name = query.value(0).toString();
                    tempItem.file_path = query.value(1).toString();
                    tempList.append(tempItem);

                }
            }else{
                qDebug()<<query.lastError();
              }
}

   return tempList;

}

void Database::insertDataToYitoaDataBase(QList<localDirectoryItem> list)
{

    int max_id = selectMaxIdFromTouchedBooksTable();

    //here we need to drop the all data from lasttimetable.
    qDebug()<<"max_id=="<<max_id;
    QSqlQuery query(database);
    query.prepare(TRUNCATEALLDATAFROMLASTTIMETABLE);
    if(query.exec()){

        qDebug()<<"===============================truncate the lasttimetable data!!!";
        localDirectoryItem item;
        for(int i=0;i<list.size();i++){

        item.file_name = list.at(i).file_name;
        item.file_path = list.at(i).file_path;
        item.progress = 0;
        item.xid =max_id+1+i;
        item.file_type = list.at(i).file_type;
       if(!databaseHasTheTargetData(list.at(i))){
          insertBookDataUntouched(item);
          insertIntoLastTimeTable(item);
          inserIntoTotaltable(item);
//           qDebug()<<"data item";
        }
      }
   }else{
      qDebug()<<query.lastError();
    }

}

QList<localDirectoryItem>* Database::getLastTimeTableFromDatabase()
{

    QList<localDirectoryItem> *tempList = new QList<localDirectoryItem>;
    if(openDataBase()){
        localDirectoryItem tempItem;
        QSqlQuery myQuery(database);
        myQuery.prepare(SELECTALLFROMLASTTIMETABLE);
        if(myQuery.exec()){
            qDebug()<<"search data successfully";
            while(myQuery.next()){
               tempItem.xid = myQuery.value(0).toInt();
               tempItem.file_name = myQuery.value(1).toString();
               tempItem.file_path = myQuery.value(2).toString();
               tempItem.progress = myQuery.value(3).toInt();
               tempItem.file_type = myQuery.value(4).toInt();
               tempList->append(tempItem);
            }
        }else{
            qDebug()<<myQuery.lastError();
        }
    }

return tempList;


}

int Database::selectMaxIdFromTouchedBooksTable()
{
   if(openDataBase()){
    QSqlQuery query(database);
    int touchedtable_max_id = 0;
    int untouchedtable_max_id = 0;
    query.prepare(SELECTMAXIDTOUCHEDTABLE);

    if(query.exec()){
        while(query.next()){
            touchedtable_max_id = query.value(0).toInt();
        }
        query.prepare(SELECTMAXIDUNTOUCHEDTABLE);
        if(query.exec()){
            while(query.next()){
                untouchedtable_max_id = query.value(0).toInt();
            }
        }

        if(touchedtable_max_id>untouchedtable_max_id&&touchedtable_max_id!=0&&untouchedtable_max_id!=0){
            return touchedtable_max_id;
        }else{
            return untouchedtable_max_id;
        }
    }
   }
    return -1;

}


/**
 * @brief Database::getAllDataFromTouchedTable
 * @return
 */
QList<localDirectoryItem>* Database::getAllDataFromTouchedTable()
{
   QList<localDirectoryItem> *templist = new QList<localDirectoryItem>;
   QSqlQuery query(database);
   localDirectoryItem item;
    query.prepare(SELECTDATAFROMTOUCHEDTABLE);
    if(query.exec()){
          while(query.next()){
              item.xid = query.value(0).toInt();
              item.file_name = query.value(1).toString();
              item.file_path = query.value(2).toString();
              templist->append(item);
          }
    }else{
        qDebug()<<query.lastError();
    }
    return templist;
}


/**
 * @brief Database::getAllDataFromTotalBooklistTable
 * @return
 */
QList<localDirectoryItem> *Database::getAllDataFromTotalBooklistTable(QString filter)
{
    QList<localDirectoryItem> *templist = new QList<localDirectoryItem>;
    QSqlQuery query(database);
    localDirectoryItem item;
     query.prepare(SELECTALLFROMTOTALBOOKSTABLEBYBOOKNAME);
     query.addBindValue(filter);
    if(query.exec()){
        while(query.next()){
          item.xid = query.value(0).toInt();
          item.file_name = query.value(1).toString();

          item.file_path = query.value(2).toString();

          item.progress = query.value(3).toInt();
          item.file_type = query.value(4).toInt();
          item.author = query.value(5).toString();
          templist->append(item);
        }
    }else{
        qDebug()<<query.lastError();
    }
    return templist;
}

QList<localDirectoryItem> *Database::getSearchResultBookList(QString str)
{
    QList<localDirectoryItem> *templist =new QList<localDirectoryItem>;
    QSqlQuery query(database);
    localDirectoryItem item;
    query.prepare(SELECTALLFROMTOTALBOOKSTABLELIKENAME);
    query.addBindValue("%"+str+"%");
    if(query.exec()){
        while(query.next()){
            item.file_name = query.value(1).toString();
            item.file_path = query.value(2).toString();
            templist->append(item);
        }
    }else{
       qDebug()<<query.lastError();
    }
    return templist;
}


/**
 * @brief operateDatabase::openDataBase
 * @return
 */
bool Database::openDataBase()
{
  bool flag = false;
  if(database.isOpen()){
      flag = true;
  }else{
      flag = database.open();
  }
  return flag;
}

Database *Database::getInstance()
{
  if(m_pInstance==NULL){
      m_pInstance = new Database;
  }
  return m_pInstance;
}




