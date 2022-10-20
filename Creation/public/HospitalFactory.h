/*
 *  HospitalFactory.h
 *  Created on: 10/19/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./BuildingFactory.h"
#include "./HospitalBuilding.h"

class HospitalFactory : public BuildingFactory
{
public:
    HospitalFactory();
    virtual ~HospitalFactory();
    
protected:
    Building* createBuilding();
};