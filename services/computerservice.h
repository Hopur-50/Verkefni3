#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "repositories/computerrepository.h"
#include "utilities/constants.h"

class ComputerService
{
public:
    ComputerService();

    std::vector<Computer> getAllComputers();
    std::vector<Computer> searchForComputers(std::string searchTerm);
    bool addComputer(Computer computer);
    bool updateComputer(Computer computer);
    bool deleteComputer(int id);
    std::vector<Scientist> getRelatedScientists(int id);

    bool addRelation(int sciID, int compID);
    bool deleteRelation(int cId, int csId);

private:
    ComputerRepository computerRepo;
    std::string currentOrder;
};

#endif // COMPUTERSERVICE_H
