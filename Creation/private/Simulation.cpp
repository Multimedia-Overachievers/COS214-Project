/*
 *  Simulation.cpp
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#include "../public/Simulation.h"

/**
 * @brief Construct a new Simulation:: Simulation object
 * 
 * @param allies 
 * @param axis 
 */
Simulation::Simulation(Faction* allies, Faction* axis)
{
    this->factions[0] = allies;
    this->factions[1] = axis;
}

/**
 * @brief Destroy the Simulation:: Simulation object
 * 
 */
Simulation::~Simulation()
{
    delete this->factions[0];
    delete this->factions[1];
    this->factions[0] = nullptr;
    this->factions[1] = nullptr;
}


/**
 * @brief Saves the current state of the simulation
 * 
 * @return MapState* 
 */
MapState* Simulation::saveLog()
{
    FactionStore* allies = this->factions[0]->getData();
    FactionStore* axis = this->factions[1]->getData();
    MapState* state = new MapState(allies, axis);
    return state;
}

/**
 * @brief Loads a previous state of the simulation
 * 
 * @param state 
 */
void Simulation::loadLog(MapState* state)
{
    FactionStore** factionStores = state->getFactionStores();
    this->factions[0]->setData(factionStores[0]);
    this->factions[1]->setData(factionStores[1]);
}