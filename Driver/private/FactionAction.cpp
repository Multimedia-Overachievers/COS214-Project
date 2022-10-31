/*
 *  FactionAction.h
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#include "../public/ConcreteFaction.h"
#include "../public/FactionAction.h"

/**
* Constructor for FactionAction
* @param c passed in faction
*/
FactionAction::FactionAction(Faction* c)
{
    myFaction = c;
}

/**
* Method to get the currently stored faction
* @return the Faction stored
*/
Faction* FactionAction::getFaction()
{
    return myFaction;
}

