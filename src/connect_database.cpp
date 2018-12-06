#include "connect_database.h"
#include <QSqlQuery>


QSqlDatabase ConnectDatabase::db = QSqlDatabase::addDatabase("QMYSQL");


ConnectDatabase::ConnectDatabase()
{

}


ConnectDatabase::~ConnectDatabase()
{
	closeDatabase();
}

// Open the Database
bool ConnectDatabase::openDatabase()
{
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("123456");
    db.setPort(3306);
    db.setDatabaseName("booklibrarymgr");

    if (!db.open())
        return false;

    return true;
}

// Close Database
void ConnectDatabase::closeDatabase()
{
    db.close();
}
