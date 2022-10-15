/*
 *  Simulation.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once

#include "../../Driver/public/Faction.h"
#include "MapState.h"


/**
 * @description Stores the state of the simulation and handles creating and fetching of logs
 */

class Simulation {
    
    public:
        Simulation(Faction* allies, Faction* axis);
        ~Simulation();
        MapState* saveLog();
        void loadLog(MapState* state);

    private:
        Faction[] factions;

        
}