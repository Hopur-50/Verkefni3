#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <QtSql>
/**
 * This file contains constants that this application uses
 */

//All constants have snake_casing names with capital letters
namespace constants
{
    const int YEAR_DIED_DEFAULT_VALUE = 0;
    const int YEAR_OF_CONSTRUCTION_VALUE = 0;
    const std::string SELECT_ALL_SCIENTISTS = "SELECT name, gender, yearOfBirth, yearOfDeath, id FROM Scientists s";
    const std::string SELECT_ALL_COMPUTERS = "SELECT name, computerType, constructed, buildYear, id FROM Computers c";
    const QString CONFIRM_DEL_COMPUTER = "Are you sure you wish to delete the selected computer?";
    const QString CONFIRM_DEL_SCIENTIST = "Are you sure you wish to delete the selected scientist?";
    const QString CONFIRM_DEL_RELATION = "Are you sure you wish to delete the selected relation?";
}

#endif // CONSTANTS_H

