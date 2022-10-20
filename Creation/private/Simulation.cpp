/*
 *  Simulation.cpp
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#include "../public/Simulation.h"

/**
 * Constructor for Simulation
 * @param allies
 * @param axis
 */
Simulation::Simulation(Faction* allies, Faction* axis)
{
    this->factions[0] = allies;
    this->factions[1] = axis;
}

/**
 * Destructor for Simulation
 */
Simulation::~Simulation()
{
    delete this->factions[0];
    delete this->factions[1];
}


/**
 * Saves the current state of the simulation
 * @return state
 */
MapState* Simulation::saveLog()
{
    FactionState* allies = this->factions[0]->getState();
    FactionState* axis = this->factions[1]->getState();
    MapState* state = new MapState(allies, axis);
    return state;
}