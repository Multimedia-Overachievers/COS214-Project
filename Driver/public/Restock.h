#pragma once
#include "FactionAction.h"

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
public:
    friend class Country;
    Restock(Faction* myFaction, Country* myCountry);
    Faction* getFaction();
    virtual void execute();

private:
    Country* myCountry;
    Name troopName;
};