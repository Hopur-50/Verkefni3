#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

#include "models/scientist.h"

namespace utils
{
    std::vector<std::string> splitString(std::string line, char delimeter);
    int stringToInt(std::string str);
    std::string stringToLower(std::string str);
    std::string intToString(int number);
    sexType intToSex(int number);
    sexType stringToSex(std::string str);
    std::string sexToString(sexType gender);
}

#endif // UTILS_H

