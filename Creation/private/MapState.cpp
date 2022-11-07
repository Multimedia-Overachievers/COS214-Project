/*
 *  MapState.cpp
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#include "../public/MapState.h"

/**
 * @brief Construct a new Map State:: Map State object
 * 
 * @param allies 
 * @param axis 
 */
MapState::MapState(FactionStore* allies, FactionStore* axis) 
{
    this->factionStores[0] = allies;
    this->factionStores[1] = axis;
}

/**
 * @brief Gets the faction states (not to be confused with stance)
 * 
 * @return FactionStore** 
 */
FactionStore** MapState::getFactionStores()
{
    return this->factionStores;
}
