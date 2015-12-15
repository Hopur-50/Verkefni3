#include "utilities/utils.h"

namespace utils
{
    sexType stringToSex(std::string str)
    {
        if (str == "Male") return Male;
        else return Female;
    }

    std::string sexToString(sexType gender)
    {
        if (gender == Male) return "Male";
        else return "Female";
    }
}
