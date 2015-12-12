#include "baserepository.h"
#include <QDebug>

BaseRepository::BaseRepository()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "secondDatabase.sqlite";
    db.setDatabaseName(dbName);

    db.open();

    if (!db.open())
        {
            qDebug() << "Could not connect.";
        }

        else
        {
            qDebug() << "Connection established.";
        }
}

BaseRepository::~BaseRepository()
{
    db.close();
}

