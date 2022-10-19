//
// Created by thoma on 10/19/2022.
//

#include "../public/MoveTroops.h"

/**
* @brief Constructor for the MoveTroops command
* @param destinationFaction The faction to which the troops will be moved.
* @param destinationCountry The country to which the troops will be moved.
* @param sourceCountry The country from which to take the troops.
*/
MoveTroops::MoveTroops(ConcreteFaction* destinationFaction, Country* destinationCountry, Country* sourceCountry, int numTroops)
                                                                                : FactionAction(destinationFaction) {
    this->destinationCountry = destinationCountry;
    this->numTroops = numTroops;
}

/**
* @brief Constructor for the MoveTroops command
* @param destinationFaction The faction to which the troops will be moved.
* @param destinationCountry The country to which the troops will be moved.
* @param sourceCountry The country from which to take the troops.
*/
void MoveTroops::execute() {
    //TODO: remove building buff before you move the troops
    for (int i = 0; this->sourceCountry->hasTroops() && i < this->numTroops; i++)
        this->destinationCountry->addTroop(this->sourceCountry->removeTroop());
}
