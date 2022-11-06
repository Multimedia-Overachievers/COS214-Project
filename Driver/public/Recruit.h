#pragma once

#include "../../Creation/public/Squad.h"
#include "../../Manipulation/public/Country.h"
#include "FactionAction.h"
#include "../../Driver/public/enums.h"
#include "../../Creation/public/Soldiers.h"

/**
 * @brief The Recruit class
 * @details This country will be used to recruit Troops.
 * One can add troops at a later stage by calling this command.
 *
 * @author Thomas Isebeck
 * @date 11/06/2022
 */
class Recruit: public FactionAction
{
private:
    Country* myCountry;
    int numTroops;
    vector<Soldiers*> mySoldiers;
    State troopstate;
    Name troopName;
public:
    Recruit(Faction *myFaction, Country *myCountry, int numTroop);
    virtual void execute();
};