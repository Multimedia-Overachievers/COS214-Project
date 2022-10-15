/*
 *  FactionAction.h
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once
#include "ConcreteFaction.h"

class FactionAction {
private:
    ConcreteFaction* myFaction;
public:
    FactionAction(ConcreteFaction* c);
    ConcreteFaction* getFaction();
    virtual bool execute() = 0;
};