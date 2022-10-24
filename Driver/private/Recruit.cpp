#include "../public/Recruit.h"
#include "../../Creation/public/Troops.h"
#include "../../Creation/public/SquadIterator.h"

/**
 * @brief Instantiate a recruit object
 * @param myFaction The faction to which the troops will be added once execute is called
 * @param myCountry The country to which the troops will be added once execute is called
 * @param numTroops The number of troops to be created
 * @param troopstate The state in which the troops will be created
 * @param troopName The name that all the troops that are recruited will have
 */
Recruit::Recruit(ConcreteFaction *myFaction, Country *myCountry, int numTroops, STATE troopstate, NAME troopName)
                                                                                                        : FactionAction(myFaction){

    mySoldiers = new Soldiers * [numTroops];

    //create the Troops and store in an array
    for (int i = 0; i < numTroops; i++) {
        //store in an array for execution
        mySoldiers[i] = new Soldiers(troopName, troopstate);
    }

}

/**
 * @brief Execute the action by creating the troops and adding them to the specified country
 */
void Recruit::execute() {
    SquadIterator iter(*mySoldiers);
    while (!iter.isDone()) {
        myCountry->addTroop(iter.current());
    }

    //Call add troop on country
    //Troops will change state depending on the size of the array
}

//No need to deallocate array, as Country will delete the created pointers