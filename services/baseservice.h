#ifndef BASESERVICE_H
#define BASESERVICE_H

#include "repositories/baserepository.h"

class BaseService
{
public:
    BaseService();

    bool addRelation(std::string sciName, std::string compName);

private:
    BaseRepository baseRepo;
};

#endif // BASESERVICE_H
