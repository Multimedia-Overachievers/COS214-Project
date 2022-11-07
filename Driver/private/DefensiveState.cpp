/*
 *  DefensiveState.cpp
 *  Created on: 11/05/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#include "../public/DefensiveState.h"

/**
 * @brief Construct a new Defensive State:: Defensive State object
 * 
 */
DefensiveState::DefensiveState(int newMorale) : FactionState(newMorale) {};

/**
 * @brief Destroy the Defensive State:: Defensive State object
 * 
 */
DefensiveState::~DefensiveState() {};

/**
 * @brief Handles the changing from the defensive state to another state
 * 
 * @param result State object, can be 'AggressiveState', 'NeutralState', 'DefensiveState'
 * @param faction Faction object
 * @param state FactionName enum, can be 'Allies', 'Axis'
 */
void DefensiveState::handleState(ActionResult result, Faction* faction)
{
    int newMorale = calculateMorale(result, faction);
    FactionState* newState = nullptr;
    string stateName = "defensive";

    if (newMorale < 50)
    {
        this->printState(faction->getName(), stateName, false);
        return;
    }
    else if (newMorale >= 50 && newMorale < 75)
    {
        newState = new NeutralState(newMorale);
    }
    else if (newMorale >= 75)
    {
        newState = new AggressiveState(newMorale);
    }

    newState->printState(faction->getName(), stateName, true);
    faction->setStance(newState);
}

StanceType DefensiveState::getStateType()
{
    return DefensiveStance;
}