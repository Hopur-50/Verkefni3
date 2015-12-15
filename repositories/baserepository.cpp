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

bool BaseRepository::addRelation(int sciID, int compID)
{
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Relations (computersID, scientistsID) VALUES (:dbCId, :dbCsId)");
    insertQuery.bindValue(":dbCId", QString::number(compID));
    insertQuery.bindValue(":dbCsId", QString::number(sciID));

    return insertQuery.exec();
}

bool BaseRepository::deleteRelation(int cId, int csId)
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Relations WHERE computersID = :cId AND scientistsID = :csId");
    deleteQuery.bindValue(":cId", QString::number(cId));
    deleteQuery.bindValue(":csId", QString::number(csId));

    return deleteQuery.exec();
}

