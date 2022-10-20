/*
 *  BuildingFactory.cpp
 *  Created on: 10/19/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */


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