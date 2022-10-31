/*
 *  ConcreteSimulator.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

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

    }
    return instance;
}


/**
 * @brief Basic function to show how google tests work.
 * @param a - First number to add.
 * @param b - Second number to add.
 * @return int - Sum of a and b.
 */
int ConcreteSimulator::TestFunction(int a, int b)
{
    return a + b;
}

/**
 * @description Notifies the simulator of a command.
 * @param command - Command to notify the simulator of.
 */
void ConcreteSimulator::notify(Faction* faction) 
{
    action(decideAction(faction));
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
FactionAction* ConcreteSimulator::decideAction(Faction *faction)
{
    double weights[2]; // Weights for the different actions 0 -> 0.5 = attack, 0.5 -> 1 = reStock
    weights[0] = 0.25; // 25%
    weights[1] = 1; // 75%
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


    if(faction->getStrength() < 3)
    {
        weights[0] /= 0.25; // Make the faction (25%) more likely to reStock
    }
    else if(faction->getStrength() > 3 && faction->getStrength() <= 5)
    {
        // No change
    }
    else if(faction->getStrength() > 6)
    {
        weights[0] *= 0.25; // Make the faction (25%) more likely to attack
    }

    double random = (double)rand() / RAND_MAX; // Random number between 0 and 1

    if(random < weights[0])
    {
        int invadingCountry = rand() % 3; // Random number between 0 and 2
        int defendingCountry = rand() % 3; // Random number between 0 and 2

        FactionAction* action = new AttackFromCountry(faction, faction->getCountry(invadingCountry), this->getOpposite(faction)->getCountry(defendingCountry));       
        return action;
    }
    else
    {
       // Random number between 5 and 15
        int numSquads = rand() % 11 + 5;
        std::vector<Troops*> squads;
        for(int i = 0; i < numSquads; i++)
        {
            squads.push_back(new Squad(SquadStd, Ready)); // @Ross-Tordiffe - I changed Squad to SquadStd because Squad is a class in the std namespace (not sure if this is the correct way to do it)
        }

        FactionAction* action = new Restock(faction, faction->getCountry(rand() % 3), Ready, squads);
        return action; // Random number between 0 and 2
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