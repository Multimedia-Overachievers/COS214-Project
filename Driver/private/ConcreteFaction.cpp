//
// Created by Thomas on 10/15/2022.
//

#include "../public/Faction.h"

class ConcreteFaction: public Faction {
    ConcreteFaction();
    void invade(Country* invadeCountry, Faction* invadeFaction);
};
