/*
 *  AggressiveState.cpp
 *  Created on: 11/05/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#include "../public/AggressiveState.h"

/**
 * @brief Construct a new Aggressive State:: Aggressive State object
 * 
 */
AggressiveState::AggressiveState(int newMorale) : FactionState(newMorale) {};

/**
 * @brief Destroy the Aggressive State:: Aggressive State object
 * 
 */
AggressiveState::~AggressiveState() {};

/**
 * @brief Handles the changing from the agressive state to another state
 * 
 * @param result State object, can be 'AggressiveState', 'NeutralState', 'DefensiveState'
 * @param faction Opposite Faction object
 * @param state FactionName enum, can be 'Allies', 'Axis'
 */
void AggressiveState::handleState(ActionResult result, Faction* faction)
{
    int newMorale = calculateMorale(result, faction);
    FactionState* newState = nullptr;
    string stateName = "aggressive";

    if (newMorale < 50)
    {
        newState = new DefensiveState(newMorale);
    }
    else if (newMorale >= 50 && newMorale < 75)
    {
        newState = new NeutralState(newMorale);
    }
    else if (newMorale >= 75)
    {
        this->printState(faction->getName(), stateName, false);
        return;
    }

    newState->printState(faction->getName(), stateName, true);
    faction->setStance(newState); 
}

StanceType AggressiveState::getStanceType()
{
    return AggressiveStance;
}