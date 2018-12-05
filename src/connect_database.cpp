#include "connect_database.h"
#include <QSqlQuery>


QSqlDatabase ConnectDatabase::db = QSqlDatabase::addDatabase("QMYSQL");


ConnectDatabase::ConnectDatabase()
{

}


ConnectDatabase::~ConnectDatabase()
{

}

// Open the Database
bool ConnectDatabase::openDatabase()
{

    db.setHostName("10.81.22.17");
    db.setDatabaseName("booklibrary");
    db.setUserName("root");
    db.setPassword("123456");
    db.setPort(3306);

    if (!db.open())
        return false;

    return true;
}

// Close Database
void ConnectDatabase::closeDatabase()
{
    db.close();
}
