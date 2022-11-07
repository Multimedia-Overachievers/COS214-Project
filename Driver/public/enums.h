/*
 *  enums.h
 *  Created on: 10/19/2022.
 *  Author: Francois Smith (u21649988)
 */

#pragma once

/**
 * @brief Defines the two factions in the game
 */
enum FactionName 
{
    Allies = 0,
    Axis
};

/**
 * @brief Defines the different types of countries that took part in the war.
 */
enum CountryName 
{
    // Allies
    France = 0,
    UnitedKingdom,
    UnitedStates,
    SovietUnion,
    Belgium,
    Netherlands,
    
    // Axis
    Germany,
    Italy,
    Japan,
    Romania,
    Hungary,
    Bulgaria,
};

/**
 * @brief Defines the different types of buildings that can be built.
 */
enum Building 
{
    Barracks,
    Hospital
};

/**
 * @brief Defines the various states a squad of troops can be in.
 */
enum State {
    Moving, 
    Ready, 
    Defeated
};


/**
 * @brief Defines the various types of troops in a country.
 */
enum Name {
    SquadStd,
    Platoon, 
    Company, 
    Battalion, 
    Army
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

/**
 * @brief Defines the result of a battle
 */
enum ActionResult {
    Win,
    Loss,
    Draw,
    None
};

/**
 * @brief Defines the different types of fonts.
 */
enum FontType {
    Cinzel = 0,
    Alegreya,
    Literata
};

/**
 * @brief Defines the different types of actions
 */
enum ActionType {
    AttackAction,
    RestockAction,
    MoveAction,
    NoneAction
};

/**
 * @brief Defines the different types of stances
 */
enum StanceType {
    NeutralStance,
    AggressiveStance,
    DefensiveStance
};

#ifndef GLOB_CONST_H
#define GLOB_CONST_H 
    #define stringify( name ) # name
    
    inline const char* convert_faction[] =
    {
        stringify(Allies),
        stringify(Axis),
    };

    inline const char* convert_country[] =
    {
        stringify(France),
        stringify(UnitedKingdom),
        stringify(UnitedStates),
        stringify(SovietUnion),
        stringify(Belgium),
        stringify(Netherlands),
        

        stringify(Germany),
        stringify(Italy),
        stringify(Japan),
        stringify(Romania),
        stringify(Hungary),
        stringify(Bulgaria),
    };

    inline const char* convert_building[] =
    {
        stringify(Barracks),
        stringify(Hospital),
    };

    inline const char* convert_state[] =
    {
        stringify(Moving),
        stringify(Ready),
        stringify(Defeated),
    };

    inline const char* convert_name[] =
    {
        stringify(SquadStd),
        stringify(Platoon),
        stringify(Company),
        stringify(Battalion),
        stringify(Army),
    };

    inline const char* convert_hp[] =
    {
        stringify(SquadHp),
        stringify(PlatoonHp),
        stringify(CompanyHp),
        stringify(BattalionHp),
        stringify(ArmyHp),
    };

    inline const char* convert_dmg[] =
    {
        stringify(SquadDmg),
        stringify(PlatoonDmg),
        stringify(CompanyDmg),
        stringify(BattalionDmg),
        stringify(ArmyDmg),
    };

    inline const char* convert_action_result[] =
    {
        stringify(Win),
        stringify(Loss),
        stringify(Draw),
        stringify(None),
    };

    inline const char* convert_font_type[] =
    {
        stringify(Cinzel),
        stringify(Alegreya),
        stringify(Literata),
    };

    inline const char* convert_action[] = 
    {
        stringify(AttackAction),
        stringify(RestockAction),
        stringify(MoveAction),
        stringify(NoneAction),
    };

    inline const char* convert_stance[] = 
    {
        stringify(NeutralStance),
        stringify(AggressiveStance),
        stringify(DefensiveStance),
    };
    
#endif  