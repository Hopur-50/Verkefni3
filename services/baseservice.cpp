#include "baseservice.h"

BaseService::BaseService()
{

}


bool BaseService::addRelation(std::string sciName, std::string compName)
{
    return baseRepo.addRelation(sciName, compName);
}
