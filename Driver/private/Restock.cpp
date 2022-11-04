#include "../public/enums.h"
#include "../../Manipulation/public/Country.h"
#include "../../Creation/public/Soldiers.h"
#include "../public/ConcreteSimulator.h"
#include "../public/Restock.h"

Restock::Restock(Faction* myFaction, Country* myCountry,  State troopstate, std::vector<Troops*> squads) : FactionAction(myFaction) {
    this->myCountry = myCountry;
    this->troopstate = troopstate;
    this->troopName = troopName;

    //DEBUG_
    type = "Restock";
}

void Restock::execute() {

    int numTroops = rand() % 20 + 10;
    std::vector<Troops*> troops;


    //get the existing troops from the country
    while (myCountry->hasTroops())
        troops.push_back(myCountry->removeTroop());


    //add the newly created troops
    for (int i = 0; i < numTroops; i++) troops.push_back(new Soldiers(troopName, troopstate));      


    //build the platooon
    Soldiers* mySoldiers = new Soldiers(troopName, troopstate);
    mySoldiers->build(troops);    

    std::cout << "Restocked " << numTroops << " troops in " << convert_country[myCountry->getName()] << std::endl;
    std::cout << mySoldiers->getReport() << std::endl;

    myCountry->troops_sized = mySoldiers;
    ConcreteSimulator::getInstance()->setLastResult(ActionResult::None);
}