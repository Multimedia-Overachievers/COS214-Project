#include "BuildInCountry.h"

BuildInCountry::BuildInCountry(ConcreteFaction * myFaction, Country* myCountry, Building* myBuilding): FactionAction(myFaction) {
    this->myCountry = myCountry;
    this->myBuilding = myBuilding;
}

bool BuildInCountry::execute() {
    myFaction->build(this->myBuilding);
    return true;
}