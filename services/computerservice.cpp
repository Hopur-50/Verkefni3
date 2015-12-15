#include "services/computerservice.h"

#include <iostream>

//This layer works as a medium between the interface and the database

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers()
{
    return computerRepo.getAllComputers(currentOrder);
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return computerRepo.searchForComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}

bool ComputerService::updateComputer(Computer computer)
{
    return computerRepo.updateComputer(computer);
}

bool ComputerService::deleteComputer(int id)
{
    return computerRepo.deleteComputer(id);
}

std::vector<Scientist> ComputerService::getRelatedScientists(int id)
{
    return computerRepo.getRelatedScientists(id);
}

bool ComputerService::addRelation(int sciID, int compID)
{
    return computerRepo.addRelation(sciID, compID);
}

bool ComputerService::deleteRelation(int cId, int csId)
{
    return computerRepo.deleteRelation(cId, csId);
}
