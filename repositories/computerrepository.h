#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>

#include "models/computer.h"
#include "models/scientist.h"

#include <QtSql>

class ComputerRepository
{
public:
    ComputerRepository();

    bool addComputer(Computer computer);
    std::vector<Computer> getAllComputers(std::string orderBy);
    std::vector<Computer> searchForComputers(std::string searchTerm);
    std::vector<Scientist> getRelatedScientists(std::string name);
    bool addRelation(std::string sciName, std::string compName);

private:

};

#endif // COMPUTERREPOSITORY_H
