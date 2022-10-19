#include "BuildInCountry.h"

/**
* @brief Constructor for the BuildInCountry command
* @param myFaction The faction to be built in.
* @param myCountry The country to be build in.
* @param myBuilding The building to be built (pass in an anonymous pointer).
* @return the ConcreteFaction stored
*/
BuildInCountry::BuildInCountry(ConcreteFaction * myFaction, Country* myCountry, Building* myBuilding): FactionAction(myFaction) {
    this->myCountry = myCountry;
    this->myBuilding = myBuilding;
}


/**
* @brief Method to get the currently stored faction.
* @return Will always return true.
*/
bool BuildInCountry::execute() {
    myFaction->build(this->myBuilding);
    return true;
}