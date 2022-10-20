/*
 *  BuildInCountry.h
 *  Created on: 10/19/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once

#include "../../Creation/public/Building.h"
#include "./FactionAction.h"

class BuildInCountry: public FactionAction 
{
public:
    BuildInCountry(ConcreteFaction * myFaction, Country* myCountry, Building* myBuilding);
    void execute() override;

private:
    Country* myCountry;
    Building* myBuilding;
};

