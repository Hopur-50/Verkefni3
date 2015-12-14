#include "services/computerservice.h"
#include<iostream>

ComputerService::ComputerService()
{
    currentOrder = constants::SORT_COMPUTER[0];
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

bool ComputerService::addRelation(std::string sciName, std::string compName)
{
    return computerRepo.addRelation(sciName, compName);
}

std::vector<Scientist> ComputerService::getRelatedScientists(std::string name)
{
    return computerRepo.getRelatedScientists(name);
}

void ComputerService::changeSortOrder(int input)
{
    currentOrder = constants::SORT_COMPUTER[input - 1];
}
