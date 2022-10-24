/*
 *  ConcreteFaction.cpp
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */


#pragma once
#include "./Faction.h"
#include "./ConcreteSimulator.h"

class ConcreteFaction: public Faction 
{
    void reStock() override;
    void attack() override;
    FactionState* getState() override;

public:
    ConcreteFaction(ConcreteSimulator* simulator, FactionName name);
    FactionStance getStance() override;
    FactionName getName() override;
    Country* getCountry(int index);
    int getStrength() override;
};
