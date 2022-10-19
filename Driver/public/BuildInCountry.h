#pragma once
#include "../../Creation/public/Building.h"
#include "FactionAction.h"

class BuildInCountry: public FactionAction {
private:
    Country* myCountry;
    Building* myBuilding;
public:
    BuildInCountry(ConcreteFaction * myFaction, Country* myCountry, Building* myBuilding);
    virtual bool execute();
};

