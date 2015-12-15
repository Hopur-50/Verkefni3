#ifndef BASESERVICE_H
#define BASESERVICE_H

#include "repositories/baserepository.h"

class BaseService
{
public:
    BaseService();

private:
    BaseRepository baseRepo;
};

#endif // BASESERVICE_H
