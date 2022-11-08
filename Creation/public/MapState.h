/*
 *  MapState.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once

#include "../../Driver/public/structs.h"

/**
 * @brief Stores the state of the world at a given time (Memento)
 * 
 */
class MapState
{
private:
    MapState(FactionStore* allies, FactionStore* axis, std::map<std::string, std::string> messageMap, ActionResult lastResult, ActionType nextAction);
    FactionStore** getFactionStores();

private:
    FactionStore* factionStores[2];
    std::map<std::string, std::string> messageMap;
    ActionResult lastResult;
    ActionType nextAction;
    friend class Simulation;
    // Other world states from simulation
};