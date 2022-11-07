/*
 *  MoveTroops.cpp
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#include "../../Manipulation/public/Country.h"
#include "../../Driver/public/enums.h"
#include "../public/MoveTroops.h"

/**
* @brief Constructor for the MoveTroops command
* @param destinationFaction The faction to which the troops will be moved.
* @param destinationCountry The country to which the troops will be moved.
* @param sourceCountry The country from which to take the troops.
*/
MoveTroops::MoveTroops(Faction* destinationFaction, Country* destinationCountry, Country* sourceCountry, int numTroops) : FactionAction(destinationFaction)
{
    this->destinationCountry = destinationCountry;
    this->numTroops = numTroops;
    this->sourceCountry = sourceCountry;
    this->action = ActionType::MoveAction;
}

/**
* @brief Constructor for the MoveTroops command
* @param destinationFaction The faction to which the troops will be moved.
* @param destinationCountry The country to which the troops will be moved.
* @param sourceCountry The country from which to take the troops.
*/
void MoveTroops::execute()
{
    vector<Troops*> removed = this->sourceCountry->removeTroops(numTroops);

    for (Troops* troop : removed)
    {
        troop->setState(Moving);
        this->destinationCountry->addTroops(troop);
    }
}
