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
AggressiveState::AggressiveState() {};

/**
 * @brief Destroy the Aggressive State:: Aggressive State object
 * 
 */
AggressiveState::~AggressiveState() {};

/**
 * @brief Handles the changing from the agressive state to another state
 * 
 * @param result State object, can be 'AggressiveState', 'NeutralState', 'DefensiveState'
 * @param faction Faction object
 * @param state FactionName enum, can be 'Allies', 'Axis'
 */
void AggressiveState::handleState(ActionResult result, Faction* faction, FactionState* state)
{
    int morale = calculateMorale(result, faction);
    FactionState* newState = nullptr;
    FactionState* oldState = state;
    string stateName = "aggressive";

    if (morale <= 25)
    {
        newState = new DefensiveState();
    }
    else if (morale > 25 && morale <= 50)
    {
        newState = new NeutralState();
    }
    else if (morale >= 75)
    {
        state->printState(faction->getName(), stateName, false);
        return;
    }

    deletePreviousState(oldState);
    state = newState;
    state->printState(faction->getName(), stateName, true);
}