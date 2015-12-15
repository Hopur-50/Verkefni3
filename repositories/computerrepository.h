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
    bool updateComputer(Computer computer);
    bool deleteComputer(int id);
    std::vector<Computer> getAllComputers(std::string orderBy);
    std::vector<Computer> searchForComputers(std::string searchTerm);
    std::vector<Scientist> getRelatedScientists(std::string name);

private:

};

#endif // COMPUTERREPOSITORY_H
