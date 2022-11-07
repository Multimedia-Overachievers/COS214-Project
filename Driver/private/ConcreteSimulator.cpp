/*
 *  ConcreteSimulator.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/FactionAction.h"
#include "../public/AttackFromCountry.h"
#include "../public/Restock.h"
#include "../public/ConcreteSimulator.h"

/**
 * @brief Constructor that initializes the factions
 */
ConcreteSimulator::ConcreteSimulator() 
{
    ConcreteFaction* allies = new ConcreteFaction(Allies);
    ConcreteFaction* axis = new ConcreteFaction(Axis);
    factions.push_back(allies);
    factions.push_back(axis);
    this->lastResult = ActionResult::None;
    this->nextAction = ActionType::NoneAction;
    srand(time(NULL));
    this->WIN_CONDITION = false;
    this->messageMap = std::map<std::string, std::string>();
    this->messageMap["Action"] = "";
    this->messageMap["Result"] = "";

}

ConcreteSimulator* ConcreteSimulator::instance = nullptr;

/**
 * @brief Gets the same instance of the singleton.
 */
ConcreteSimulator* ConcreteSimulator::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ConcreteSimulator();
        for (Faction* faction : instance->factions)
        {
            faction->createCountries();
        }
    }
    return instance;
}

/**
 * @description Notifies the simulator of a command.
 * @param command - Command to notify the simulator of.
 */
void ConcreteSimulator::notify(Faction* faction) 
{
    action(decideAction(faction));
    std::cout << std::endl;
}

/**
 * @description Performs an action on a faction.
 * @param factionAction - Action to perform on a faction.
 */
void ConcreteSimulator::action(FactionAction *factionAction) 
{
    factionAction->execute();
}

/**
 * @description Decides what action to perform on a faction.
 * @param faction - Faction to decide an action for.
 * @return FactionAction - Action to perform on the faction.
 */
FactionAction* ConcreteSimulator::decideAction(Faction* faction)
{
    double weight = 0.5; // Weights for the different actions < weight = attack, > weight = reStock
    // Get the faction's stance and adjust the weight accordingly
    switch (faction->getStance()->getStanceType())
    {
        case DefensiveStance:
            weight = 0.25; // 75% chance to reStock, 25% chance to attack
            break;
        case NeutralStance:
            weight = 0.5; // 50% chance to reStock, 50% chance to attack
            break;
        case AggressiveStance:
            weight = 0.75; // 25% chance to reStock, 75% chance to attack
            break;
    }

    double random = (double)rand() / RAND_MAX; // Random number between 0 and 1
    
    std::cout << "Weights: " << weight << " Random: " << random << endl; 
    if(random < weight)
    {
        int invadingCountry = rand() % faction->getStrength();
        int defendingCountry = rand() % getOpposite(faction)->getStrength();
        nextAction = ActionType::AttackAction;    
        return new AttackFromCountry(faction, faction->getCountry(invadingCountry), this->getOpposite(faction)->getCountry(defendingCountry));
    }
    else
    {
        Country* country = faction->getCountry(rand() % 6); // Random number between 0 and 5
        nextAction = ActionType::RestockAction;
        return new Restock(faction, country); // Random number between 0 and 5
    }
}

/**
 * @description Returns one of the two factions from the simulator
 * @param name - Name of the faction to return as an enum
 * @return ConcreteFaction* - The faction at the index
 */
Faction* ConcreteSimulator::getFaction(FactionName name) 
{
    if(name == Allies)
    {
        return factions[0];
    }
    else if(name == Axis)
    {
        return factions[1];
    }
    else
    {
        return nullptr;
    }
}

/**
 * @description Takes in a faction and returns the opposite faction
 * @param faction - Faction to get the opposite of
 * @return ConcreteFaction* - The opposite faction
 */
Faction* ConcreteSimulator::getOpposite(Faction* faction)
{
    if(faction->getName() == Allies)
    {
        return factions[1];
    }
    else if(faction->getName() == Axis)
    {
        return factions[0];
    }
    else
    {
        std::cout << "Error: Faction not found" << std::endl;
        return nullptr;
    }
}

/**
 * @description Returns the number of factions in the simulator
 * @return int - Number of factions in the simulator
 */
void ConcreteSimulator::captureCountry(Country* country, Faction* faction)
{
    Faction* opposite = getOpposite(faction); 

    std::cout << "BEFORE:" << std::endl;
    // Output all the countries in the faction
    std::cout << "Faction: " << faction->getName() << " Countries: ";
    for (Country* country : faction->countries)
    {
        std::string countryName = convert_country[country->getName()];
        std::cout << countryName << " ";
    }
    std::cout << std::endl;

    // Output all the countries in the opposite faction
    std::cout << "Opposite Faction: " << opposite->getName() << " Countries: ";
    for (Country* country : opposite->countries)
    {
        std::string countryName = convert_country[country->getName()];
        std::cout << countryName << " ";
    }
    std::cout << std::endl;

    faction->addCountry(country);
    getOpposite(faction)->removeCountry(country);      
    this->WIN_CONDITION = getOpposite(faction)->getStrength() == 0;  

    std::cout << "AFTER:" << std::endl;
    // Output all the countries in the faction
    std::cout << "Faction: " << faction->getName() << " Countries: ";
    for (Country* country : faction->countries)
    {
        std::string countryName = convert_country[country->getName()];
        std::cout << countryName << " ";
    }
    std::cout << std::endl;

    // Output all the countries in the opposite faction
    std::cout << "Opposite Faction: " << opposite->getName() << " Countries: ";
    for (Country* country : opposite->countries)
    {
        std::string countryName = convert_country[country->getName()];
        std::cout << countryName << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Sets the outcome of the last battle for weighting purposes
 * 
 * @param result - The result of the last battle
 */
void ConcreteSimulator::setLastResult(ActionResult result){
    lastResult = result;
}

/**
 * @brief Gets the outcome of the last battle for weighting purposes
 * 
 * @return ActionResult - The result of the last battle
 */
ActionResult ConcreteSimulator::getLastResult(){
    return lastResult;
}

/**
 * @brief Get the next action to be displayed on the UI
 * 
 */
ActionType ConcreteSimulator::getNextAction()
{
    return nextAction;
}

/**
 * @brief Constructs an image path based on passed in country
 * @return std::string - The path to the image
 */
std::string ConcreteSimulator::getImagePath(CountryName country){
    std::string path = "../Media/";
    Country* countryPtr = nullptr;
    for(Country* c : countries){
        if(c->getName() == country){
            countryPtr = c;
            break;
        }
    }

    if(countryPtr == nullptr){
        return "";
    }
    else{
      
        std::string countryName = convert_country[countryPtr->getName()];
        std::string factionName = convert_faction[countryPtr->getOwner()];
        path += countryName;
        path += factionName;
        path += ".png";
        return path;
    }

    return path;
}

/**
 * @brief Constructs an image path based on passed in faction
 * @return std::string - The path to the image
 */
std::string ConcreteSimulator::getImagePath(ActionType action)
{
    std::string path = "../Media/";
    std::string actionName = convert_action[action];
    path += actionName;
    path += ".png";
    return path;
}