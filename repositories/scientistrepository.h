#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include <vector>
#include <string>

#include "models/scientist.h"
#include "models/computer.h"
#include <QtSql>

class ScientistRepository
{
public:
    ScientistRepository();

    bool addScientist(Scientist scientist);
    bool updateScientist(Scientist scientist);
    bool deleteScientist(int id);
    std::vector<Scientist> getAllScientists(std::string orderBy);
    std::vector<Scientist> searchForScientists(std::string searchTerm);
    std::vector<Computer> getRelatedComputers(int id);
};

#endif // SCIENTISTREPOSITORY_H
