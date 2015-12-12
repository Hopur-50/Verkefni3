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
            qDebug() << "badshit";
        }

        else
        {
            qDebug() << "goodshit";
        }
}

BaseRepository::~BaseRepository()
{
    db.close();
}

