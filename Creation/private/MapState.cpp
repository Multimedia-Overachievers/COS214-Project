/*
 *  MapState.cpp
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#include "../public/MapState.h"

/**
 * Constructor for MapState
 * @param allies
 * @param axis
 */
MapState::MapState(FactionStore* allies, FactionStore* axis) 
{
    this->factionStores[0] = allies;
    this->factionStores[1] = axis;
}

/**
 * Gets the faction states
 * @return factionStates
 */
FactionStore** MapState::getFactionStores()
{
    return this->factionStores;
}
