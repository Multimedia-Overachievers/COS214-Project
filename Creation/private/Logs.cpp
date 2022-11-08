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
MapState* Logs::getLog() {
    // pop the last log
    if (this->logs.size() > 0)
    {
        MapState* state = this->logs.back();
        this->logs.pop_back();
        std::cout << "Log loaded" << std::endl;
        return state;
    }
    else
    {
        return nullptr;
    }

}

/**
 * @brief Creates a log and pushes it to the logs vector
 * 
 * @param state 
 */
void Logs::createLog(MapState* state) {
    this->logs.push_back(state);
}