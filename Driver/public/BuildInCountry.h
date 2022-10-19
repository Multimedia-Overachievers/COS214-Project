//
// Created by thomas on 10/19/2022.
//

#pragma once
#include "../../Creation/public/Building.h"
#include "./FactionAction.h"

class BuildInCountry: public FactionAction {
private:
    Country* myCountry;
    Building* myBuilding;
public:
    BuildInCountry(ConcreteFaction * myFaction, Country* myCountry, Building* myBuilding);
    virtual bool execute();
};

