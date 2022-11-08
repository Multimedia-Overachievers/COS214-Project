/*
 *  Simulation.cpp
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#include "../../Driver/public/ConcreteSimulator.h"
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
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    FactionStore* allies = this->factions[0]->getData();
    FactionStore* axis = this->factions[1]->getData();
    std::map<std::string, std::string> messageMap;
    messageMap["Action"] = simulator->messageMap["Action"];
    messageMap["Result"] = simulator->messageMap["Result"];
    ActionResult lastResult = simulator->getLastResult();
    ActionType nextAction = simulator->getNextAction();
    MapState* state = new MapState(allies, axis, messageMap, lastResult, nextAction);
    return state;
}

/**
 * @brief Loads a previous state of the simulation
 * 
 * @param state 
 */
void Simulation::loadLog(MapState* state)
{   
    if(state != nullptr)
    {
        ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
        FactionStore** factionStores = state->getFactionStores();
        this->factions[0]->setData(factionStores[0]);
        this->factions[1]->setData(factionStores[1]);
        simulator->messageMap["Action"] = state->messageMap["Action"];
        simulator->messageMap["Result"] = state->messageMap["Result"];
        simulator->setLastResult(state->lastResult);
        simulator->setNextAction(state->nextAction);
    }
    // else do nothing
}