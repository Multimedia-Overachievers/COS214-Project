/*
 *  Faction.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "../../Manipulation/public/Country.h"
#include "../../Creation/public/FactionState.h"
#include "../public/enums.h"
#include "./enums.h"
#include <list>

class Faction {
public:
    Faction() = default;
    virtual ~Faction() = default;
    virtual FactionState* getState() = 0;
    virtual FactionStance getStance() = 0;
    virtual FactionName getName() = 0;
    virtual int getStrength() = 0;
    virtual void removeCountry(Country* country);
    virtual void addCountry(Country* country);

protected: 
    std::list<Country*> countries;
    FactionStance stance;
    FactionName name;
};
