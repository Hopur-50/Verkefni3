#include "baseservice.h"

BaseService::BaseService()
{

}


bool BaseService::addRelation(int sciID, int compID)
{
    return baseRepo.addRelation(sciID, compID);
}
