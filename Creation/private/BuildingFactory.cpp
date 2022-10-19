#include "../public/BuildingFactory.h"

/**
 * @brief Construct a new Building Factory:: Building Factory object
 * 
 */
BuildingFactory::BuildingFactory() {};

/**
 * @brief Destroy the Building Factory:: Building Factory object
 * 
 */
BuildingFactory::~BuildingFactory() {};


/**
 * @brief Function used when a building needs to be created. Calls the virtual createBuilding() method
 * 
 * @return Building* 
 */
Building* BuildingFactory::create()
{
    return createBuilding();
}