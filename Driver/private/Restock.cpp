#include "../public/Restock.h"
#include "../public/enums.h"
#include "../../Creation/public/Soldiers.h"

Restock::Restock(ConcreteFaction* myFaction, Country* myCountry,  State troopstate, std::vector<Troops*> squads) : FactionAction(myFaction) {
    this->myCountry = myCountry;
    this->troopstate = troopstate;
    this->troopName = troopName;
}

void Restock::execute() {
    //Add a variable number of troops
    int numTroops = rand() % 20 + 10;

    //create a vector of troops
    vector<Troops*> troops;

    //get the existing troops from the country
    while (myCountry->hasTroops())
        troops.push_back(myCountry->removeTroop());

    //add the newly created troops
    for (int i = 0; i < numTroops; i++)
        troops.push_back(new Soldiers(troopName, troopstate));

    //build the platooon
    Soldiers* mySoldiers;
    mySoldiers->build(troops);

    //assign the new platoon to the country
    myCountry->troops_sized = mySoldiers;
}