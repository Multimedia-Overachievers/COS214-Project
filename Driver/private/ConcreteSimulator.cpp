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
    srand(time(NULL));
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
    double weights[2]; // Weights for the different actions 0 -> 0.5 = attack, 0.5 -> 1 = reStock
    weights[0] = 0.25; // 75%
    weights[1] = 1; // 25%
    // if(faction->getStance() == FactionStance::Aggressive)
    // {
    //     weights[0] = 0.75; // 75%
    //     weights[1] = 1; // 25%
    // }
    // else if(faction->getStance() == FactionStance::Passive)
    // {
    //     weights[0] = 0.5; // 50% 
    //     weights[1] = 1; // 50%
    // }
    // else if(faction->getStance() == FactionStance::Defensive)
    // {   
    //     weights[0] = 0.25; // 25%
    //     weights[1] = 1; // 75%
    // }


    if(faction->getStrength() <= 3)
    {
        weights[0] /= 0.25; // Make the faction (25%) more likely to reStock
    }
    else if(faction->getStrength() >= 4 && faction->getStrength() <= 6)
    {
        // No change
    }
    else if(faction->getStrength() >= 7)
    {
        weights[0] *= 0.25; // Make the faction (25%) more likely to attack
    }

    double random = (double)rand() / RAND_MAX; // Random number between 0 and 1
    
    std::cout << "Weights: " << weights[0] << " Random: " << random << endl; 
    if(random < weights[0])
    {
        int invadingCountry = rand() % 6; // Random number between 0 and 5
        int defendingCountry = rand() % 6; // Random number between 0 and 5    
        return new AttackFromCountry(faction, faction->getCountry(invadingCountry), this->getOpposite(faction)->getCountry(defendingCountry));
    }
    else
    {
        Country* country = faction->getCountry(rand() % 6); // Random number between 0 and 5
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
        std::cout << "Allies, returning Axis" << std::endl;
        std::cout << "Axis: " << factions[1]->getName() << std::endl;
        return factions[1];
    }
    else if(faction->getName() == Axis)
    {
        std::cout << "Axis, returning Allies" << std::endl;
        std::cout << "Allies: " << factions[0]->getName() << std::endl;
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
    faction->addCountry(country);
    getOpposite(faction)->removeCountry(country);    
    
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
std::string ConcreteSimulator::getImagePath(ActionType action){
{
    std::string path = "../Media/";
    std::string actionName = convert_action[action];
    path += actionName;
    path += ".png";
    return path;
}