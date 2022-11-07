/*
 *  Logs.cpp
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#include "../public/Logs.h"

/**
 * @brief Construct a new Logs:: Logs object
 * 
 */
Logs::Logs() {}

/**
 * @brief Destroy the Logs:: Logs object
 * 
 */
Logs::~Logs() 
{
    for (size_t i = 0; i < this->logs.size(); i++)
    {
        delete this->logs[i];
    }
}

/**
 * @brief Gets the logs
 * 
 * @return std::vector<MapState*> 
 */
std::vector<MapState*> Logs::getLogs() {
    return this->logs;
}

/**
 * @brief Creates a log and pushes it to the logs vector
 * 
 * @param state 
 */
void Logs::CreateLog(MapState* state) {
    this->logs.push_back(state);
}