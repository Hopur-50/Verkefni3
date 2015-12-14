#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>


ScientistRepository::ScientistRepository()
{

}

bool ScientistRepository::addScientist(Scientist scientist)
{
    QSqlQuery query;

    std::string name = scientist.getName();
    enum sexType sex = scientist.getSex();
    int yearBorn = scientist.getYearBorn();
    int yearDied = scientist.getYearDied();

    if (yearDied == constants::YEAR_DIED_DEFAULT_VALUE)
    {
        query.prepare("INSERT INTO Scientists (name, gender, yearOfBirth) VALUES(:dbname,:dbgender,:dbyearOfBirth)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbgender", QString::fromStdString(utils::sexToString(sex)));
        query.bindValue(":dbyearOfBirth", QString::number(yearBorn));
    }
    else
    {
        query.prepare("INSERT INTO Scientists (name, gender, yearOfBirth, yearOfDeath) VALUES(:dbname,:dbgender,:dbyearOfBirth, :dbyearOfDeath)");
        query.bindValue(":dbname", QString::fromStdString(name));
        query.bindValue(":dbgender", QString::fromStdString(utils::sexToString(sex)));
        query.bindValue(":dbyearOfBirth", QString::number(yearBorn));
        query.bindValue(":dbyearOfDeath", QString::number(yearDied));
    }
    return query.exec();
}

bool ScientistRepository::updateScientist(Scientist scientist)
{
    QSqlQuery query;
    std::string name = scientist.getName();
    enum sexType sex = scientist.getSex();
    int yearBorn = scientist.getYearBorn();
    int yearDied = scientist.getYearDied();
    int id = scientist.getId();

    query.prepare("UPDATE Scientists SET name = :dbname, gender = :dbgender, yearOfBirth = :dbyearOfBirth, yearOfDeath = :dbyearOfDeath WHERE id = :dbid");
    query.bindValue(":dbname", QString::fromStdString(name));
    query.bindValue(":dbgender", QString::fromStdString(utils::sexToString(sex)));
    query.bindValue(":dbyearOfBirth", QString::number(yearBorn));
    query.bindValue(":dbyearOfDeath", QString::number(yearDied));
    query.bindValue(":dbid", QString::number(id));

    return query.exec();
}

std::vector<Scientist> ScientistRepository::getAllScientists(std::string orderBy)
{
    std::vector<Scientist> scientists;

    QString orderQuery = QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) + " " + QString::fromStdString(orderBy);
    QSqlQuery query(orderQuery);

    while (query.next())
    {

        std::string name = query.value(0).toString().toStdString();
        std::string sexString = query.value(1).toString().toStdString();
        enum sexType sex;

        if(sexString == "m" || sexString == " m" || sexString == "male" || sexString == " male") //We change sex to string so we can read correctly from the database.
        {
            sex = male;
        }
        else
        {
            sex = female;
        }

        int yearBorn = query.value(2).toInt();
        int yearDied = query.value(3).toInt();
        int id = query.value(4).toInt();

        if (query.value(3).isNull())
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
    return scientists;
}

std::vector<Scientist> ScientistRepository::searchForScientists(std::string searchTerm)
{
    std::vector<Scientist> foundScientists;
    QString QSearchTerm = QString::fromStdString(searchTerm);
    QString searchQuery = QString::fromStdString(constants::SELECT_ALL_SCIENTISTS) +
    " WHERE s.name LIKE '%" + QSearchTerm + "%'" +
    " OR s.gender LIKE '%" + QSearchTerm + "%'" +
    " OR s.yearOfBirth LIKE '%" + QSearchTerm + "%'" +
    " OR s.yearOfDeath LIKE '%" + QSearchTerm + "%'";

    QSqlQuery query(searchQuery);

    while (query.next())
    {
        std::string name = query.value(0).toString().toStdString();
        std::string sexString = query.value(1).toString().toStdString();
        enum sexType sex;
        if(sexString == "m" || sexString == " m" || sexString == "male" || sexString == " male")
        {
            sex = male;
        }
        else
        {
            sex = female;
        }
        int yearBorn = query.value(2).toInt();
        int yearDied = query.value(3).toInt();
        int id = query.value(4).toInt();

        if (query.value(3).isNull())
        {
            Scientist sciGuy(name, sex, yearBorn);
            sciGuy.setId(id);
            foundScientists.push_back(sciGuy);
        }
        else
        {
            Scientist sciGuy(name, sex, yearBorn, yearDied);
            sciGuy.setId(id);
            foundScientists.push_back(sciGuy);
        }
    }

    return foundScientists;
}

std::vector<Computer> ScientistRepository::getRelatedComputers(std::string name)
{
    QSqlQuery query;
    std::vector<Computer> computers;
    query.prepare("SELECT id FROM Scientists WHERE name = :dbName");
    query.bindValue(":dbName", QString::fromStdString(name));
    query.exec();
    query.next();

    int scientistId = query.value(0).toInt();

    query.prepare("SELECT computersID FROM Relations WHERE scientistsID = :dbCsId");
    query.bindValue(":dbCsId", scientistId);
    query.exec();

    QSqlQuery query2;

    while(query.next())
    {
        int cId=query.value(0).toInt();
        query2.prepare(QString::fromStdString(constants::SELECT_ALL_COMPUTERS) + " WHERE id = :dbCId");
        query2.bindValue(":dbCId", cId);
        query2.exec();

        while(query2.next())
        {
            std::string name = query2.value(0).toString().toStdString();
            std::string type = query2.value(1).toString().toStdString();
            bool wasItConstructed = query2.value(2).toBool();
            int yearOfConstruction = query2.value(3).toInt();
            int id = query.value(4).toInt();

            if(query2.value(2).isNull())
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
    }
    return computers;
}


