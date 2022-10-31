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
    this->factions[0] = nullptr;
    this->factions[1] = nullptr;
}


/**
 * Saves the current state of the simulation
 * @return state
 */
MapState* Simulation::saveLog()
{
    FactionStore* allies = this->factions[0]->getData();
    FactionStore* axis = this->factions[1]->getData();
    MapState* state = new MapState(allies, axis);
    return state;
}

/**
 * Loads a previous state of the simulation
 * @param state
 */
void Simulation::loadLog(MapState* state)
{
    FactionStore** factionStores = state->getFactionStores();
    this->factions[0]->setData(factionStores[0]);
    this->factions[1]->setData(factionStores[1]);
}