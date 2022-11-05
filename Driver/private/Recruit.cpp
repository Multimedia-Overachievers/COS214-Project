#include "../public/Recruit.h"
#include "../../Creation/public/Troops.h"
#include "../../Creation/public/SquadIterator.h"
#include "../../Driver/public/enums.h"

/**
 * @brief Instantiate a recruit object
 * @param myFaction The faction to which the troops will be added once execute is called
 * @param myCountry The country to which the troops will be added once execute is called
 * @param numTroops The number of troops to be created
 * @param troopstate The state in which the troops will be created
 * @param troopName The name that all the troops that are recruited will have
 */
Recruit::Recruit(Faction *myFaction, Country *myCountry, int numTroops) : FactionAction(myFaction)
{
    this->myFaction = myFaction;
    this->myCountry = myCountry;
    this->numTroops = numTroops;
}

/**
 * @brief Execute the action by creating the troops and adding them to the specified country
 */
void Recruit::execute()
{
    myCountry->addTroops(numTroops);
}

//No need to deallocate array, as Country will delete the created pointers