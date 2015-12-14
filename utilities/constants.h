#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <QtSql>
/**
 * This file contains constants that this application uses
 */

namespace constants                             //All constants have snake_casing names with capital letters
{
    const int YEAR_DIED_DEFAULT_VALUE = 13337;
    const int YEAR_OF_CONSTRUCTION_VALUE = 80083;
    const std::string SELECT_ALL_SCIENTISTS = "SELECT name, gender, yearOfBirth, yearOfDeath, id FROM Scientists s";
    const std::string SELECT_ALL_COMPUTERS = "SELECT name, computerType, constructed, buildYear, id FROM Computers c";
}

#endif // CONSTANTS_H

