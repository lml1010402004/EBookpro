#ifndef OPERATEDATABASE_H
#define OPERATEDATABASE_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QFile>
#include<QList>
#include<QString>
#include<QSqlDatabase>
#include<QDir>
#include<QDebug>
#include<QFileInfoList>


typedef struct bookFromLocalDirectory{
   int xid;
   QString file_name;
   QString file_path;
   int file_type;
   int progress;
   bool cover_exist;
   QString author;

}localDirectoryItem;

class Database
{
public:

    bool openDataBase();
    static  Database* getInstance();
    QSqlDatabase database;

private:

    QList<QString> currentBookNameList;
    QList<localDirectoryItem> existRecordIntheDatabase;
    bool callAllRecordFromDataBase;
    bool createBooksTable(QSqlQuery query);
     Database();
     ~Database();





public:
    localDirectoryItem tempItem;
    bool insertBookDataUntouched(localDirectoryItem item);
    bool insertIntoLastTimeTable(localDirectoryItem item);
    bool inserIntoTotaltable(localDirectoryItem item);

    bool deleteADataFromUntouchedTable(localDirectoryItem item);
    bool insertADataToTouchedTable(localDirectoryItem item);

    bool databaseHasTheTargetData(localDirectoryItem item);
    QList<localDirectoryItem> getAllFileInTheTargetDirectory(QString directory);
    QList<localDirectoryItem> allRecordIntheDataBase();
    void insertDataToYitoaDataBase(QList<localDirectoryItem> list);
    QList<localDirectoryItem>* getLastTimeTableFromDatabase();
    int selectMaxIdFromTouchedBooksTable();


    QList<localDirectoryItem>* getAllDataFromTouchedTable();
    QList<localDirectoryItem>* getLastTwoRecordsFromTouchedTable();

    QList<localDirectoryItem>* getAllDataFromTotalBooklistTable(QString filter);
    QList<localDirectoryItem>* getSearchResultBookList(QString str);


};

#endif // OPERATEDATABASE_H
