/*
 *  AggressiveState.cpp
 *  Created on: 05/11/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#include "../public/AggressiveState.h"

AggressiveState::AggressiveState() {};

AggressiveState::~AggressiveState() {};

void AggressiveState::handleState(ActionResult result, Faction* faction, FactionState* state)
{
    int morale = calculateMorale(result, faction);
    FactionState* newState = nullptr;
    FactionState* oldState = state;

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
        state->printState(faction->getName(), "aggressive", false);
        return;
    }

    deletePreviousState(oldState);
    state = newState;
    state->printState(faction->getName(), "aggressive", true);
}