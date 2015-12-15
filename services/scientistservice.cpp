#include "services/scientistservice.h"

#include <algorithm>

//This layer works as a medium between the interface and the database

ScientistService::ScientistService()
{

}

std::vector<Scientist> ScientistService::getAllScientists()
{
    return scientistRepo.getAllScientists(currentOrder);
}

std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}

bool ScientistService::updateScientist(Scientist scientist)
{
    return scientistRepo.updateScientist(scientist);
}

bool ScientistService::deleteScientist(int id)
{
    return scientistRepo.deleteScientist(id);
}

std::vector<Computer> ScientistService::getRelatedComputers(int id)
{
    return scientistRepo.getRelatedComputers(id);
}


