#pragma once
#include "FactionAction.h"
#include "../../Creation/public/Soldiers.h"

class Country;

/**
 * @brief A concrete command to regenerate troops.
 * @details Particularly when a country is running low on troops.
 *
 * @author Thomas Isebeck
 * @date 11/06/2022
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