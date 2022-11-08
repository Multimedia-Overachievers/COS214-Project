/*
 *  FactionState.cpp
 *  Created on: 10/31/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#include "../public/FactionState.h"

/**
 * @brief Construct a new Faction State:: Faction State object
 * 
 */
FactionState::FactionState(int newMorale) 
{
    morale = newMorale;
};

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
        cout << getFactionName(name) << " is now " << state << endl;
    }
    else
    {
        cout << getFactionName(name) << " is still " << state << endl;
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
 * @brief Returns the current morale of a Faction
 * 
 * @return int 
 */
int FactionState::getMorale()
{
    return morale;
}

/**
 * @brief Calculate the morale of a faction based on: the number of troops, number of countries in the faction and the result of a battle
 * 
 * @param faction Opposite Faction object
 * @return int 
 */
/*
 * if morale < 50, defensive; if morale >= 50 && morale < 75, neutral; if morale >= 75, aggressive
 * if opposite is null, morale *= 1.2
 * if the result is a win, morale *= 1.4, if the result is a loss, morale *= 0.6, if the result is a draw, morale *= 0.9
 * if numTroops < 300, morale *= 0.8; if numTroops >= 300 && numTroops < 700, morale *= 1; if numTroops >= 700, morale *= 1.2
 * if numCountries < 4, morale *= 0.8; if numCountries >= 4 && numCountries < 7, morale *= 1; if numCountries >= 7, morale *= 1.2
*/
int FactionState::calculateMorale(ActionResult result, Faction* faction)
{   
    double newMorale = this->getMorale();
    int numCountries = faction->getStrength();
    int numTroops = faction->getTotalTroops();

    // Total number of troops
    if (numTroops < 25)
    {
        newMorale *= 0.8;
    }
    else if (numTroops >= 25 && numTroops < 40)
    {
        newMorale *= 1;
    }
    else if (numTroops >= 40)
    {
        newMorale *= 1.2;
    }

    // Total number of countries
    if (numCountries < 4)
    {
        newMorale *= 0.8;
    }
    else if (numCountries >= 4 && numCountries < 7)
    {
        newMorale *= 1;
    }
    else if (numCountries >= 7)
    {
        newMorale *= 1.2;
    }

    switch (result)
    {
        case Win:
            newMorale *= 1.4;
            break;

        case Loss:
            newMorale *= 0.6;
            break;

        case Draw:
            newMorale *= 0.8;
            break;  
        
        default:
            newMorale *= 1;
            break;
    }

    return (int) newMorale;
}   
