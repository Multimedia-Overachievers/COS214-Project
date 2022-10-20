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

/**
 * @brief Defines the various states a country can be in.
 */
enum FactionStance{
    Defensive,
    Aggressive,
    Passive
};

/**
 * @brief Defines the various states a squad of troops can be in.
 */
enum STATE {
    MOVING, 
    READY, 
    DEFEATED
};


/**
 * @brief Defines the various types of squads in a country.
 */
enum NAME {
    SQUAD, 
    PLATOON, 
    COMPANY, 
    BATTALION, 
    ARMY
};