/*
 *  BuildingFactory.h
 *  Created on: 10/19/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "Building.h"

/**
 * @description BuildingFactory 
 * 
 */
class BuildingFactory 
{
    protected:
        virtual Building* createBuilding() = 0;

    public:
        BuildingFactory();
        virtual ~BuildingFactory();
        Building* create();
        
};