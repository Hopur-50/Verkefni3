#include "computer.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

Computer::Computer(std::string name, std::string type, bool wasItConstructed)
{
    this->name = name;
    this->type = type;
    this->wasItConstructed = wasItConstructed;
    this->yearOfConstruction = constants::YEAR_OF_CONSTRUCTION_VALUE;
}

Computer::Computer(std::string name, std::string type, bool wasItConstructed, int yearOfConstruction)
{
    this->name = name;
    this->type = type;
    this->wasItConstructed = wasItConstructed;
    this->yearOfConstruction = yearOfConstruction;
}

std::string Computer::getName() const
{
    return name;
}

std::string Computer::getType() const
{
    return type;
}

int Computer::getYearOfConstruction() const
{
    return yearOfConstruction;
}

bool Computer::getWasItConstructed() const
{
    return wasItConstructed;
}

void Computer::setId(int id)
{
   this->id = id;
}

int Computer::getId() const
{
    return id;
}
