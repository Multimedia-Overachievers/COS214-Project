/*
 *  Faction.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "../../Manipulation/public/Country.h"
#include "../../Manipulation/public/FactionObserver.h"
#include "./enums.h"
#include <list>

class FactionState;
class FactionStore;

class Faction 
{
public:
    Faction()
    { 
        this->observer = new FactionObserver((ConcreteFaction*)this);
    };
    virtual FactionStore* getData() = 0;
    virtual void setData(FactionStore* store) = 0;
    virtual FactionState* getStance() = 0;
    virtual StanceType getStanceType() = 0;
    virtual FactionName getName() = 0;
    virtual int getStrength() = 0;
    virtual Country* getCountry(int index) = 0;
    virtual void removeCountry(Country* country) = 0;
    virtual void addCountry(Country* country) = 0;
    virtual void notify() = 0;
    virtual void changeState(ActionResult result) = 0;
    virtual void createCountries() = 0;
    virtual int getTotalTroops() = 0;
    virtual void setStance(FactionState*) = 0;
    virtual ~Faction() { delete observer; };
    std::list<Country*> countries;

protected: 
    FactionState* stance;
    FactionName name;
    FactionObserver* observer;
};
