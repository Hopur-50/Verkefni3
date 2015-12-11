#include "baserepository.h"

BaseRepository::BaseRepository()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "secondDatabase.sqlite";
    db.setDatabaseName(dbName);

    db.open();
}

