/*
 *  MapState.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once
#include "../../Driver/public/structs.h"

/**
 * @description Stores the state of the world at a given time
 */
class MapState
{
private:
    MapState(FactionStore* allies, FactionStore* axis);
    FactionStore** getFactionStores();

private:
    FactionStore* factionStores[2];
    friend class Simulation;
    // Other world states from simulation
};