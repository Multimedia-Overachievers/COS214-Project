#pragma once
#include "FactionAction.h"
#include "../../Creation/public/Soldiers.h"

/*
 * Currently, restock will simply add
 *
 */

class Restock: public FactionAction
{
private:
    Country* myCountry;
    Faction* myFaction;
    Soldiers** mySoldiers;
    State troopstate;
    Name troopName;
public:
    friend class Country;
    Restock(Faction* myFaction, Country* myCountry,  State troopstate, std::vector<Troops*> squads);
    Faction* getFaction();
    virtual void execute();
};

//faction->getStance() == FactionStance::Defensive