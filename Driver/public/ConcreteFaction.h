/*
 *  ConcreteFaction.cpp
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */


#pragma once
#include "./Faction.h"

class ConcreteFaction: public Faction 
{
    ConcreteFaction(Simulator* simulator, std::string name);
    void reStock() override;
    void attack() override;
    FactionState* getState() override;
    FactionStance getStance() override;
    int getStrength() override;
};
