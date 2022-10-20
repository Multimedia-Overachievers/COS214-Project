/*
 *  ConcreteFaction.cpp
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#include "../public/Faction.h"

class ConcreteFaction: public Faction 
{
    ConcreteFaction();
    void invade(Country* invadeCountry, Faction* invadeFaction);
};
