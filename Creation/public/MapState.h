/*
 *  MapState.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once
#include "FactionState.h"

/**
 * @description Stores the state of the world at a given time
 */
class MapState
{
    private:
        MapState(FactionState* allies, FactionState* axis);
        FactionState** getFactionStates();

    private:
        FactionState* factionStates[2];
        friend class Simulation;
        // Other world states from simulation
};