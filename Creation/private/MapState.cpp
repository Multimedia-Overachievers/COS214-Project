#include "../public/MapState.h"

/**
 * Constructor for MapState
 * @param allies
 * @param axis
 */
MapState::MapState(FactionState* allies, FactionState* axis) 
{
    this->factionStates[0] = allies;
    this->factionStates[1] = axis;
}

/**
 * Gets the faction states
 * @return factionStates
 */
FactionState** MapState::getFactionStates()
{
    return this->factionStates;
}
