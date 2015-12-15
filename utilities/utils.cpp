#include "utilities/utils.h"

namespace utils
{
    sexType stringToSex(std::string str)
    {
        if (str == "Male") return Male;
        else if (str == "Female") return Female;
        else return Other;
    }

    std::string sexToString(sexType gender)
    {
        if (gender == Male) return "Male";
        else if (gender == Female) return "Female";
        else return "Other";
    }
}
