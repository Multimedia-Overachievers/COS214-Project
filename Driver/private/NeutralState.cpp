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
NeutralState::NeutralState() {};

/**
 * @brief Destroy the Aggressive State:: Aggressive State object
 * 
 */
NeutralState::~NeutralState() {};

/**
 * @brief Handles the changing from the agressive state to another state
 * 
 * @param result State object, can be 'AggressiveState', 'NeutralState', 'DefensiveState'
 * @param faction Faction object
 * @param state FactionName enum, can be 'Allies', 'Axis'
 */
void NeutralState::handleState(ActionResult result, Faction* faction, FactionState* state)
{
    int morale = calculateMorale(result, faction);
    FactionState* newState = nullptr;
    FactionState* oldState = state;
    string stateName = "neutal";

    if (morale <= 25)
    {
        newState = new DefensiveState();
    }
    else if (morale > 25 && morale <= 50)
    {
        state->printState(faction->getName(), stateName, false);
        return;
    }
    else if (morale >= 75)
    {
        newState = new AggressiveState();
    }

    deletePreviousState(oldState);
    state = newState;
    state->printState(faction->getName(), stateName, true);
}