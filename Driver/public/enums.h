/*
 *  enums.h
 *  Created on: 10/19/2022.
 *  Author: Francois Smith (u21649988)
 */

#pragma once

/**
 * @brief Defines the different types of countries that took part in the war.
 */
enum CountryName {
    Bulgaria,
    France,
    Germany,
    Italy,
    Japan,
    OttomanEmpire,
    Portugal,
    Russia,
    UnitedKingdom,
    UnitedStates
};

enum FactionStance{
    Defensive,
    Aggressive,
    Passive
};

enum STATE {
    MOVING, 
    READY, 
    DEFEATED
};

enum NAME {
    SQUAD, 
    PLATOON, 
    COMPANY, 
    BATTALION, 
    ARMY
};