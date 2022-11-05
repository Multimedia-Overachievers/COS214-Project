/*
 *  FactionState.cpp
 *  Created on: 05/11/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#include "../public/FactionState.h"

/**
 * @brief Construct a new Faction State:: Faction State object
 * 
 */
FactionState::FactionState() {};

/**
 * @brief Destroy the Faction State:: Faction State object
 * 
 */
FactionState::~FactionState() {};

/**
 * @brief Prints out the state of a faction
 * 
 * @param name FactionName enum, can be 'Allies', 'Axis'
 * @param state String equivalent of a state type, can be 'aggressive', 'neutral', 'defensive'
 * @param change Boolean indicating if a faction's state was changed
 */
void FactionState::printState(FactionName name, string state, bool change)
{
    if (change)
    {   
        cout << getFactionName(name) << " is now" << state << endl;
    }
    else
    {
        cout << getFactionName(name) << " is still" << state << endl;
    }
}

/**
 * @brief Returns the string equivalent of a FactionName enum
 * 
 * @param name FactionName enum, can be 'Allies', 'Axis'
 * @return string 
 */
string FactionState::getFactionName(FactionName name)
{
    switch (name)
    {
        case Allies:
            return "Allies";
            break;

        case Axis:
            return "Axis";
            break;
        
        default:
            return "";
            break;
    }
}

/**
 * @brief Handles the deletion of a state
 * 
 * @param state The previous state of a Faction
 */
void FactionState::deletePreviousState(FactionState* state)
{
    if (state != nullptr)
    {
        delete state;
    }
}

/**
 * @brief Calculate the morale of a faction based on: the number of troops, number of countries in the faction and the result of a battle
 * 
 * @param faction 
 * @return int 
 */
int FactionState::calculateMorale(ActionResult result, Faction* faction)
{   
    
}   