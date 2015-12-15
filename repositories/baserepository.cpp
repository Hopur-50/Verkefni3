#include "baserepository.h"
#include "utilities/constants.h"
#include <QDebug>

BaseRepository::BaseRepository()
{
    db = getDatabaseConnection();
}

BaseRepository::~BaseRepository()
{
    db.close();
}

QSqlDatabase BaseRepository::getDatabaseConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "secondDatabase.sqlite";
    db.setDatabaseName(dbName);

    db.open();

    return db;
}



