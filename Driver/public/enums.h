/*
 *  enums.h
 *  Created on: 10/19/2022.
 *  Author: Francois Smith (u21649988)
 */

#pragma once

/**
 * @brief Defines the two factions in the game
 */
enum FactionName {
    Allies,
    Axis
};

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
 * @brief Defines the various types of troops in a country.
 */
enum NAME {
    SQUAD,
    PLATOON, 
    COMPANY, 
    BATTALION, 
    ARMY
};

/**
 * @brief Defines the default hit points for each type of troop 
 */
enum Hp {
    SquadHp = 100,
    PlatoonHp = 200,
    CompanyHp = 300,
    BattalionHp = 400,
    ArmyHp = 500
};

/**
 * @brief Defines the default damage for each type of troop 
 */
enum Dmg {
    SquadDmg = 10,
    PlatoonDmg = 20,
    CompanyDmg = 30,
    BattalionDmg = 40,
    ArmyDmg = 50
};