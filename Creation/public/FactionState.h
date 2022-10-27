/*
 *  FactionState.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once

#include "../../Manipulation/public/Country.h"
#include "../../Driver/public/enums.h"
#include <list>

/**
 * @description Stores the state of a faction at a given time
 */
class FactionState
{
    
private:
    FactionState(std::list<Country*> countries, FactionStance stance, FactionName name);
    std::list<Country*> getCountries();
    FactionStance getStance();
    FactionName getName();
    void setStance(FactionStance stance);

private:
    std::list<Country*> countries;
    FactionStance stance;
    FactionName name;
    friend class ConcreteFaction;
    friend class FactionObserver;
};