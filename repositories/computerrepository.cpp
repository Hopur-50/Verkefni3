#include "computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>

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
        //std::string queryAdd = "INSERT INTO Computer (name, type, wasItConstructed, yearOfConstruction) VALUES";
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

    query.prepare("UPDATE Computers SET name = :dbname, type = :dbtype, wasItConstructed = :dbwasItConstructed, yearOfConstruction = :dbyearOfConstruction WHERE id = :dbid");
    query.bindValue(":dbname", QString::fromStdString(name));
    query.bindValue(":dbtype", QString::fromStdString(type));
    query.bindValue(":dbwasItConstructed", wasItConstructed);
    query.bindValue(":dbyearOfConstruction", QString::number(yearOfConstruction));
    query.bindValue(":dbid", QString::number(id));

    return query.exec();
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

        if (query.value(2) == false)
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

        if(query.value(2).isNull())
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

std::vector<Scientist> ComputerRepository::getRelatedScientists(std::string name)
{
    QSqlQuery query;
    std::vector<Scientist> scientists;
    query.prepare("SELECT id FROM Computers WHERE name = :dbName");
    query.bindValue(":dbName", QString::fromStdString(name));
    query.exec();
    query.next();

    int computerId = query.value(0).toInt();

    query.prepare("SELECT scientistsID FROM Relations WHERE computersID = :dbCId");
    query.bindValue(":dbCId", computerId);
    query.exec();

    QSqlQuery query2;

    while(query.next())
    {
        int csId = query.value(0).toInt();
        query2.prepare("SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists WHERE id = :dbCsId");
        query2.bindValue(":dbCsId", csId);
        query2.exec();
        while(query2.next())
        {
            std::string name = query2.value(0).toString().toStdString();
            enum sexType sex;
            std::string sexString = query2.value(1).toString().toStdString();
            if(sexString == "m" || sexString == " m" || sexString == "male" || sexString == " male")
            {
                sex = male;
            }
            else
            {
                sex = female;
            }
            int yearBorn = query2.value(2).toInt();
            int yearDied = query2.value(3).toInt();
            int id = query2.value(4).toInt();

            if (query2.value(3).isNull())
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

