/*
 *  NeutralState.cpp
 *  Created on: 05/11/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#include "../public/NeutralState.h"

/**
 * @brief Construct a new Aggressive State:: Aggressive State object
 * 
 */
NeutralState::NeutralState(int newMorale) : FactionState(newMorale) {};

/**
 * @brief Destroy the Aggressive State:: Aggressive State object
 * 
 */
NeutralState::~NeutralState() {};

/**
 * @brief Handles the changing from the neutral state to another state
 * 
 * @param result State object, can be 'AggressiveState', 'NeutralState', 'DefensiveState'
 * @param faction Faction object
 * @param state FactionName enum, can be 'Allies', 'Axis'
 */
void NeutralState::handleState(ActionResult result, Faction* faction)
{
    int newMorale = calculateMorale(result, faction);
    FactionState* newState = nullptr;
    string stateName = "neutal";

    if (newMorale < 50)
    {
        newState = new DefensiveState(newMorale);
    }
    else if (newMorale >= 50 && newMorale < 75)
    {
        this->printState(faction->getName(), stateName, false);
        return;
    }
    else if (newMorale >= 75)
    {
        newState = new AggressiveState(newMorale);
    }

    newState->printState(faction->getName(), stateName, true);
    faction->setStance(newState);
}

StanceType NeutralState::getStanceType()
{
    return NeutralStance;
}