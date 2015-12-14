#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "repositories/computerrepository.h"
#include "models/scientist.h"
#include "utilities/constants.h"

class ComputerService
{
public:
    ComputerService();

    std::vector<Computer> getAllComputers();
    std::vector<Computer> searchForComputers(std::string searchTerm);
    bool addComputer(Computer computer);
    bool updateComputer(Computer computer);
    bool addRelation(std::string sciName, std::string compName);
    std::vector<Scientist> getRelatedScientists(std::string name);

private:
    ComputerRepository computerRepo;
    std::string currentOrder;
};

#endif // COMPUTERSERVICE_H
