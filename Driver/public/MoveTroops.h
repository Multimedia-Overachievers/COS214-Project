/**
 * @brief A concrete move troops
 * @details Moves a passed in number of troops from the source
 * to the destination country.
 *
 * @author Thomas Isebeck
 * @date 11/06/2022
 */

#pragma once
#include "./FactionAction.h"

class Country;

/**
 * @brief A concrete command to move troops between countries.
 */

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
