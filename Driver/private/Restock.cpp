// #include "../../Manipulation/public/Country.h"
// #include "../../Creation/public/Soldiers.h"
#include "../public/ConcreteSimulator.h"
#include "../public/Restock.h"

/**
 * @brief Constructor for the Restock command
 * @param myFaction The faction to be built in (passed to FactionAction)
 * @param myCountry The country to be restocked.
 */
Restock::Restock(Faction* myFaction, Country* myCountry) : FactionAction(myFaction) 
{
    this->myCountry = myCountry;
    this->action = ActionType::RestockAction;

    std::string faction(convert_faction[myFaction->getName()]);
    std::string country(convert_country[myCountry->getName()]);
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    simulator->messageMap["Action"] = faction + " is restocking " + country + ". ";
}

/**
 * @brief Restocks the country with troops
 */
void Restock::execute() 
{

    const int NUM_TROOPS = rand() % 20 + 10;


    //add the newly created troops
    myCountry->addTroops(NUM_TROOPS);

    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    simulator->messageMap["Result"] = std::to_string(NUM_TROOPS) + " troops were added. Totaling " + std::to_string(myCountry->getNumTroops()) + " troops.";

    std::cout << "Restocked " << NUM_TROOPS << " troops in " << convert_country[myCountry->getName()] << std::endl;
    // std::cout << myCountry->myTroops->getReport() << std::endl;
    

    ConcreteSimulator::getInstance()->setLastResult(ActionResult::None);
}