#include "services/scientistservice.h"

#include <algorithm>

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

std::vector<Computer> ScientistService::getRelatedComputers(std::string name)
{
    return scientistRepo.getRelatedComputers(name);
}


