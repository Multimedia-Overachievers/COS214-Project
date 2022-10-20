/*
 *  Logs.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once

#include "./MapState.h"

/**
 * @description A log of the previous states of each faction
 */
class Logs 
{
public:
    Logs();
    ~Logs();
    std::vector<MapState*> getLogs();
    void CreateLog(MapState* state);

private:
    std::vector<MapState*> logs;
};