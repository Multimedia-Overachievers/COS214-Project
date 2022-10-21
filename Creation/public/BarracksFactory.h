/*
 *  BarracksFactory.h
 *  Created on: 10/21/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./BuildingFactory.h"
#include "./BarracksBuilding.h"

class BarracksFactory : public BuildingFactory
{
public:
    BarracksFactory();
    virtual ~BarracksFactory();
    
protected:
    Building* createBuilding();
};