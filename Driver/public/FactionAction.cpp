/*
 *  FactionAction.h
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#include "FactionAction.h"

FactionAction::FactionAction(ConcreteFaction* c) {
    myFaction = c;
}
ConcreteFaction* FactionAction::getFaction() {
    return myFaction;
}

