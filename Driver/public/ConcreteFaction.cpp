//
// Created by Thomas on 10/15/2022.
//

#include "Faction.h"

class ConcreteFaction: public Faction {
    ConcreteFaction();
    void invade(Country* invadeCountry, Faction* invadeFaction);
};
