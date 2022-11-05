#pragma once
#include "FactionAction.h"
#include "../../Creation/public/Soldiers.h"

class Country;

/**
 * @brief A concrete command to regenerate troops.
 * Particularly when a country is running low on troops.
 */

class Restock: public FactionAction
{
private:
    Country* myCountry;
    State troopstate;
    Name troopName;
public:
    friend class Country;
    Restock(Faction* myFaction, Country* myCountry,  State troopstate, std::vector<Troops*> squads);
    Faction* getFaction();
    virtual void execute();
};