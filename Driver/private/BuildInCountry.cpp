//
// Created by thomas on 10/19/2022.
//

#include "../public/BuildInCountry.h"

/**
* @brief Constructor for the BuildInCountry command.
* @param myFaction The faction to be built in (passed to FactionAction).
* @param myCountry The country to be build in.
* @param myBuilding The building to be built (pass in an anonymous pointer).
*/
BuildInCountry::BuildInCountry(ConcreteFaction * myFaction, Country* myCountry, Building* myBuilding): FactionAction(myFaction) {
    this->myCountry = myCountry;
    this->myBuilding = myBuilding;
}

/**
* @brief passes the building to the faction to be built.
*/
void BuildInCountry::execute() {
    // Uncommented until functions are made to allow compilation
    // myFaction->build(this->myCountry, this->myBuilding);
}