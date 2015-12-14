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

bool BaseRepository::addRelation(std::string sciName, std::string compName)
{
    QSqlQuery query;

    query.prepare("SELECT id FROM Computers WHERE name = :dbComputer");
    query.bindValue(":dbComputer", QString::fromStdString(compName));
    query.exec();
    query.next();
    int cId = query.value(0).toInt();

    QSqlQuery query2;
    query2.prepare("SELECT id FROM Scientists WHERE name = :dbScientist");
    query2.bindValue(":dbScientist", QString::fromStdString(sciName));
    query2.exec();
    query2.next();
    int csId = query2.value(0).toInt();

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Relations (computersID, scientistsID) VALUES (:dbCId, :dbCsId)");
    insertQuery.bindValue(":dbCId", QString::number(cId));
    insertQuery.bindValue(":dbCsId", QString::number(csId));
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

