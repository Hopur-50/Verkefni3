#ifndef BASESERVICE_H
#define BASESERVICE_H

#include "repositories/baserepository.h"

class BaseService
{
public:
    BaseService();

    bool addRelation(int sciID, int compID);

private:
    BaseRepository baseRepo;
};

#endif // BASESERVICE_H
