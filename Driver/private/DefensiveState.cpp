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
DefensiveState::DefensiveState() {};

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
void DefensiveState::handleState(ActionResult result, Faction* faction, FactionState* state)
{
    int morale = calculateMorale(result, faction);
    FactionState* newState = nullptr;
    FactionState* oldState = state;
    string stateName = "defensive";

    if (morale <= 25)
    {
        state->printState(faction->getName(), stateName, false);
        return;
    }
    else if (morale > 25 && morale <= 50)
    {
        newState = new NeutralState();
    }
    else if (morale >= 75)
    {
        newState = new AggressiveState();
    }

    deletePreviousState(oldState);
    state = newState;
    state->printState(faction->getName(), stateName, true);
}