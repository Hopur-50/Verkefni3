#include "services/computerservice.h"
#include <iostream>

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

std::vector<Scientist> ComputerService::getRelatedScientists(std::string name)
{
    return computerRepo.getRelatedScientists(name);
}

bool ComputerService::addRelation(int sciID, int compID)
{
    return computerRepo.addRelation(sciID, compID);
}
