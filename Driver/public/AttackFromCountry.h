/*
 *  AttackFromCountry.h
 *  Created on: 10/19/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once
#include "./FactionAction.h"

class Country;

/**
 * @brief A concrete command to allow countries to attack one another.
 */

class AttackFromCountry: public FactionAction 
{
public:
    AttackFromCountry(Faction* myFaction, Country* attacker, Country* toAttack);
    virtual void execute() override;

private:
    Country* attacker;
    Country* toAttack;
};
