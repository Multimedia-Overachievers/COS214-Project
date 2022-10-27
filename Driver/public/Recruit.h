#pragma once

#include "../../Creation/public/Squad.h"
#include "../../Manipulation/public/Country.h"
#include "FactionAction.h"
#include "../../Driver/public/enums.h"
#include "../../Creation/public/Soldiers.h"

class Recruit: public FactionAction
{
private:
    Country* myCountry;
    int numTroops;
    Soldiers** mySoldiers;
public:
    Recruit(Faction* myFaction, Country* myCountry, int numTroops, State troopstate, Name troopName);
    virtual void execute();
};