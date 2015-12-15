#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "repositories/scientistrepository.h"
#include "utilities/constants.h"

class ScientistService
{
public:
    ScientistService();
    std::vector<Scientist> getAllScientists();
    std::vector<Scientist> searchForScientists(std::string searchTerm);
    bool addScientist(Scientist scientist);
    bool updateScientist(Scientist scientist);
    bool deleteScientist(int id);
    std::vector<Computer> getRelatedComputers(int id);

private:
    ScientistRepository scientistRepo;
    std::string currentOrder;
};

#endif // SCIENTISTSERVICE_H
