#include "computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>

//Transfers information to and from the database

ComputerRepository::ComputerRepository()
{

}

bool ComputerRepository::addComputer(Computer computer)
{
    QSqlQuery query;

    std::string name = computer.getName();
    std::string type = computer.getType();
    bool wasItConstructed = computer.getWasItConstructed();
    int IntWasItConstructed = wasItConstructed;

    if (wasItConstructed == false)
    {
        query.prepare("INSERT INTO Computers (name, computerType, constructed) VALUES(:dbname,:dbtype,:dbwasItConstructed)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));

    }
    else
    {
        int yearOfConstruction = computer.getYearOfConstruction();
        query.prepare("INSERT INTO Computers (name, computerType, constructed, buildYear) VALUES(:dbname,:dbtype,:dbwasItConstructed,:dbyearOfConstruction)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbtype", QString::fromStdString(type));
        query.bindValue(":dbwasItConstructed", QString::number(IntWasItConstructed));
        query.bindValue(":dbyearOfConstruction", QString::number(yearOfConstruction));
    }

    return query.exec();
}

bool ComputerRepository::updateComputer(Computer computer)
{
    QSqlQuery query;

    std::string name = computer.getName();
    std::string type = computer.getType();
    bool wasItConstructed = computer.getWasItConstructed();
    int yearOfConstruction = computer.getYearOfConstruction();
    int id = computer.getId();

    query.prepare("UPDATE Computers SET name = :dbname, computerType = :dbtype, constructed = :dbwasItConstructed, buildYear = :dbyearOfConstruction WHERE id = :dbid");
    query.bindValue(":dbname", QString::fromStdString(name));
    query.bindValue(":dbtype", QString::fromStdString(type));
    query.bindValue(":dbwasItConstructed", wasItConstructed);
    query.bindValue(":dbyearOfConstruction", QString::number(yearOfConstruction));
    query.bindValue(":dbid", QString::number(id));

    return query.exec();
}

bool ComputerRepository::deleteComputer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Relations WHERE computersID = :dbId");
    query.bindValue(":dbId", id);
    query.exec();

    QSqlQuery query2;
    query2.prepare("DELETE FROM Computers WHERE id = :dbId");
    query2.bindValue(":dbId", id);
    return query2.exec();
}


std::vector<Computer> ComputerRepository::getAllComputers(std::string orderBy)
{
    std::vector<Computer> computers;

    QString orderQuery = QString::fromStdString(constants::SELECT_ALL_COMPUTERS) + " " + QString::fromStdString(orderBy);
    QSqlQuery query(orderQuery);

    while (query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string type = query.value(1).toString().toStdString();
        bool wasItConstructed = query.value(2).toInt();
        int yearOfConstruction = query.value(3).toInt();
        int id = query.value(4).toInt();

        if (query.value(2) == false) // Checks whether the computer was constructed
        {
            Computer compMachine(name, type, wasItConstructed);
            compMachine.setId(id);
            computers.push_back(compMachine);
        }
        else
        {
            Computer compMachine(name, type, wasItConstructed, yearOfConstruction);
            compMachine.setId(id);
            computers.push_back(compMachine);
        }
    }

    return computers;
}

std::vector<Computer> ComputerRepository::searchForComputers(std::string searchTerm)
{
    std::vector<Computer> foundComputers;
    QString QSearchTerm = QString::fromStdString(searchTerm);
    QString searchQuery = QString::fromStdString(constants::SELECT_ALL_COMPUTERS)+
    " WHERE c.name LIKE '%" + QSearchTerm + "%'" +
    " OR c.computerType LIKE '%" + QSearchTerm + "%'" +
    " OR c.constructed LIKE '%" + QSearchTerm + "%'" +
    " OR c.buildYear LIKE '%" + QSearchTerm + "%'";

    QSqlQuery query(searchQuery);

    while(query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string type = query.value(1).toString().toStdString();
        int wasItConstructed = query.value(2).toInt();
        int yearOfConstruction = query.value(3).toInt();
        int id = query.value(4).toInt();

        if(query.value(2).isNull()) //Checks whether the computer was constructed
        {
            Computer compMachine(name, type, wasItConstructed);
            compMachine.setId(id);
            foundComputers.push_back(compMachine);
        }
        else
        {
            Computer compMachine(name, type, wasItConstructed, yearOfConstruction);
            compMachine.setId(id);
            foundComputers.push_back(compMachine);
        }
    }
    return foundComputers;
}

std::vector<Scientist> ComputerRepository::getRelatedScientists(int id)
{
    QSqlQuery query;
    std::vector<Scientist> scientists;
    query.prepare("SELECT scientistsID FROM Relations WHERE computersID = :dbCId");
    query.bindValue(":dbCId", id);
    query.exec();

    QSqlQuery query2;

    while(query.next())
    {
        int csId = query.value(0).toInt();
        query2.prepare(QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) + " WHERE id = :dbCsId");
        query2.bindValue(":dbCsId", csId);
        query2.exec();
        while(query2.next())
        {
            std::string name = query2.value(0).toString().toStdString();
            sexType sex;
            std::string sexString = query2.value(1).toString().toStdString();
            if(sexString == "Male" || sexString == "m")
            {
                sex = Male;
            }
            else
            {
                sex = Female;
            }
            int yearBorn = query2.value(2).toInt();
            int yearDied = query2.value(3).toInt();
            int id = query2.value(4).toInt();

            if (query2.value(3).isNull()) //Checks whether the scientist is alive
            {
                Scientist sciGuy(name, sex, yearBorn);
                sciGuy.setId(id);
                scientists.push_back(sciGuy);
            }
            else
            {
                Scientist sciGuy(name, sex, yearBorn, yearDied);
                sciGuy.setId(id);
                scientists.push_back(sciGuy);
            }
        }
    }
    return scientists;
}

bool ComputerRepository::addRelation(int sciID, int compID)
{
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Relations (computersID, scientistsID) VALUES (:dbCId, :dbCsId)");
    insertQuery.bindValue(":dbCId", QString::number(compID));
    insertQuery.bindValue(":dbCsId", QString::number(sciID));

    return insertQuery.exec();
}

bool ComputerRepository::deleteRelation(int cId, int csId)
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Relations WHERE computersID = :cId AND scientistsID = :csId");
    deleteQuery.bindValue(":cId", QString::number(cId));
    deleteQuery.bindValue(":csId", QString::number(csId));
    return deleteQuery.exec();
}
