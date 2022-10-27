/*
 *  MoveTroops.h
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once
#include "./FactionAction.h"

class MoveTroops: public FactionAction
{
public:
    MoveTroops(Faction* destinationFaction, Country* destinationCountry, Country* sourceCountry, int numTroops);
    virtual void execute();

private:
    Country* destinationCountry;
    Country* sourceCountry;
    int numTroops;
};
