/*
 *  BuildingFactory.h
 *  Created on: 10/19/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./Building.h"

/**
 * @brief BuildingFactory 
 */
class BuildingFactory 
{
public:
    BuildingFactory();
    virtual ~BuildingFactory();
    Building* create();

protected:
    virtual Building* createBuilding() = 0;   
};