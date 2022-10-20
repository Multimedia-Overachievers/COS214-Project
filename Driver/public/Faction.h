/*
 *  Faction.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "Simulator.h"
#include "../../Manipulation/public/Country.h"
#include "../../Creation/public/FactionState.h"
#include "./enums.h"
#include <list>

class Faction {
public:
    explicit Faction(Simulator* simulator, std::string name);
    void reStock();
    void attack();
    FactionState* getState();
    FactionStance getStance();
    int getStrength();

private:
    Simulator* simulator;
    std::list<Country*> countries;
    FactionStance stance;
};
