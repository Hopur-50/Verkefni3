#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

enum sexType
{
    Female,
    Male,
    Other
};
                            //All classes are PascalCasing and all functions and variables are camelCasing.
class Scientist
{
public:
    Scientist(std::string name, sexType sex, int yearBorn);
    Scientist(std::string name, sexType sex, int yearBorn, int yearDied);

    std::string getName() const;
    enum sexType getSex() const;
    int getYearBorn() const;
    int getYearDied() const;

    void setId(int id);
    int getId() const;

private:
    std::string name;
    enum sexType sex;
    int yearBorn;
    int yearDied;
    int id;
};

#endif // SCIENTIST_H
