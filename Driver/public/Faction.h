/*
 *  Faction.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "../../Manipulation/public/Country.h"
#include "../../Creation/public/FactionState.h"
#include "./enums.h"
#include <list>

class Faction {
public:
    Faction(FactionName name) : name(name){ stance = FactionStance::Passive; };
    virtual FactionState* getState() = 0;
    virtual FactionStance getStance() = 0;
    virtual FactionName getName() = 0;
    virtual int getStrength() = 0;
    virtual void removeCountry(Country* country) = 0;
    virtual void addCountry(Country* country) = 0;

protected: 
    std::list<Country*> countries;
    FactionStance stance;
    FactionName name;
};
