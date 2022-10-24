#pragma once
#include "FactionAction.h"
#include "../../Creation/public/Soldiers.h"

/*
 * Currently, restock will simply add
 *
 */

class Restock: public FactionAction {
private:
    Country* myCountry;
    ConcreteFaction* myFaction;
    Soldiers** mySoldiers;
    STATE troopstate;
    NAME troopName;
public:
    friend class Country;
    Restock(ConcreteFaction* myFaction, Country* myCountry,  STATE troopstate, NAME troopName);
    ConcreteFaction* getFaction();
    virtual void execute() = 0;
};

//faction->getStance() == FactionStance::Defensive