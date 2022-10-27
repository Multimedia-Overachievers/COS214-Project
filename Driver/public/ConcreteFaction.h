/*
 *  ConcreteFaction.cpp
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once
#include "./Faction.h"

class ConcreteFaction: public Faction 
{
public:
    ConcreteFaction(FactionName name);
    ~ConcreteFaction() override;
    FactionState* getState() override;
    FactionStance getStance() override;
    FactionName getName() override;
    Country* getCountry(int index);
    int getStrength() override;
    void removeCountry(Country* country) override;
    void addCountry(Country* country) override;
};

    // virtual FactionState* getState() = 0;
    // virtual FactionStance getStance() = 0;
    // virtual FactionName getName() = 0;
    // virtual int getStrength() = 0;
    // virtual void removeCountry(Country* country);
    // virtual void addCountry(Country* country);