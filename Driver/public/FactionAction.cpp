/*
 *  FactionAction.h
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#include "FactionAction.h"

/**
* Constructor for FactionAction
* @param c passed in faction
*/
FactionAction::FactionAction(ConcreteFaction* c) {
    myFaction = c;
}

/**
* Method to get the currently stored faction
* @return the ConcreteFaction stored
*/
ConcreteFaction* FactionAction::getFaction() {
    return myFaction;
}

