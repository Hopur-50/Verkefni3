#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <string>

//To include enum sexType
#include "models/scientist.h"

namespace utils
{
    sexType stringToSex(std::string str);
    std::string sexToString(sexType gender);
}

#endif // UTILS_H

