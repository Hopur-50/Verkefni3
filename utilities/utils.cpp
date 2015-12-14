#include "utilities/utils.h"

#include <sstream>
#include <cstdlib>

namespace utils
{
    std::vector<std::string> splitString(std::string line, char delimeter) 
    {
        std::vector<std::string> result;

        std::string currentWord = "";

        for (unsigned int i = 0; i < line.length(); i++) 
        {
            char currentChar = line[i];

            if (currentChar == delimeter) 
            {
                if  (currentWord.length())
                {
                    result.push_back(currentWord);
                    currentWord = "";
                }
            } 
            else 
            {
                if (currentChar != '\n') 
                {
                    currentWord += currentChar;
                }
            }
        }

        if (currentWord.length()) 
        {
            result.push_back(currentWord);
        }
        return result;
    }

    int stringToInt(std::string str)
    {
        return atoi(str.c_str());
    }

    std::string stringToLower(std::string str) 
    {
        std::string result = "";

        for (unsigned int i = 0; i < str.length(); i++)
        {
            char currentCharacter = str[i];

            if (currentCharacter <= 90 && currentCharacter >= 65)
            {
                result += currentCharacter + 32;
            }
            else
            {
                result += currentCharacter;
            }
        }
        return result;
    }

    std::string intToString(int number) 
    {
        std::stringstream stream;
        stream << number;
        return stream.str();
    }

    sexType intToSex(int number)
    {
        return static_cast<sexType>(number);
    }

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
