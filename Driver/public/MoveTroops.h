#pragma once
#include "../../Creation/public/Building.h"
#include "FactionAction.h"

class MoveTroops: public FactionAction {
private:
    Country* destinationCountry;
    Country* sourceCountry;
    int numTroops;
public:
    MoveTroops(ConcreteFaction* destinationFaction, Country* destinationCountry, Country* sourceCountry, int numTroops);
    virtual void execute();
};
