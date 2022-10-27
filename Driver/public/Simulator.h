/*
 *  Simulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once 
#include "./FactionAction.h"
#include "./Faction.h"
#include <string>
#include <iostream>

class ConcreteFaction;

class Simulator
{
public:
    virtual void action(FactionAction* factionAction) = 0;
    virtual void notify(Faction* faction) = 0;
    virtual FactionAction* decideAction(Faction* faction) = 0;
    virtual Faction* getFaction(FactionName name) = 0; // 0 = Allies, 1 = Axis
    virtual Faction* getOpposite(Faction* faction) = 0;
    virtual void captureCountry(Country* country, Faction* faction) = 0;
};
