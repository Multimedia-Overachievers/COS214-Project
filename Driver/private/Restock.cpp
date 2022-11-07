#include "../../Manipulation/public/Country.h"
#include "../../Creation/public/Soldiers.h"
#include "../public/ConcreteSimulator.h"
#include "../public/Restock.h"

Restock::Restock(Faction* myFaction, Country* myCountry) : FactionAction(myFaction) {
    this->myCountry = myCountry;
    this->troopName = troopName;
    this->action = ActionType::Restock;
}

void Restock::execute() {

    const int NUM_TROOPS = rand() % 20 + 10;

    //add the newly created troops
    myCountry->addTroops(NUM_TROOPS);

    std::cout << "Restocked " << NUM_TROOPS << " troops in " << convert_country[myCountry->getName()] << std::endl;
    std::cout << myCountry->myTroops->getReport() << std::endl;

    ConcreteSimulator::getInstance()->setLastResult(ActionResult::None);
}