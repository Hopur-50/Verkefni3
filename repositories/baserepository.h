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

private:
    QSqlDatabase db;
    QSqlDatabase getDatabaseConnection();
};

#endif // BASEREPOSITORY_H
