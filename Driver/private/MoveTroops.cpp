/*
 *  MoveTroops.cpp
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#include "../public/MoveTroops.h"
#include "../../Driver/public/enums.h"

/**
* @brief Constructor for the MoveTroops command
* @param destinationFaction The faction to which the troops will be moved.
* @param destinationCountry The country to which the troops will be moved.
* @param sourceCountry The country from which to take the troops.
*/
MoveTroops::MoveTroops(ConcreteFaction* destinationFaction, Country* destinationCountry, Country* sourceCountry, int numTroops)
                                                                                                        : FactionAction(destinationFaction)
{
    this->destinationCountry = destinationCountry;
    this->numTroops = numTroops;
    this->sourceCountry = sourceCountry;
}

/**
* @brief Constructor for the MoveTroops command
* @param destinationFaction The faction to which the troops will be moved.
* @param destinationCountry The country to which the troops will be moved.
* @param sourceCountry The country from which to take the troops.
*/
void MoveTroops::execute()
{
    //TODO: remove building buff before you move the troops
    for (int i = 0; this->sourceCountry->hasTroops() && i < this->numTroops; i++) {
        Troops* myTroop = this->sourceCountry->removeTroop();
        myTroop->state = Moving;
        this->destinationCountry->addTroop(myTroop);
    }
}
