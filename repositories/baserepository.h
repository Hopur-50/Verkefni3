#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

#include <vector>
#include <string>

#include "models/computer.h"
#include "models/scientist.h"

#include <QtSql>

class BaseRepository
{
public:
    BaseRepository();
    ~BaseRepository();
    bool addRelation(std::string sciName, std::string compName);
    bool deleteRelation(int cId, int csId);

private:
    QSqlDatabase db;
};

#endif // BASEREPOSITORY_H
