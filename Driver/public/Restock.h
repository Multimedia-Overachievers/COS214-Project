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
    ConcreteFaction* myFaction;
    Soldiers** mySoldiers;
    State troopstate;
    Name troopName;
public:
    friend class Country;
    Restock(ConcreteFaction* myFaction, Country* myCountry,  State troopstate, std::vector<Troops*> squads);
    ConcreteFaction* getFaction();
    virtual void execute();
};

//faction->getStance() == FactionStance::Defensive