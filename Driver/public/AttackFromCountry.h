/*
 *  AttackFromCountry.h
 *  Created on: 10/19/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once

#include "./FactionAction.h"
#include "./ConcreteFaction.h"

class AttackFromCountry: public FactionAction 
{
public:
    AttackFromCountry(ConcreteFaction* myFaction, Country* attacker, Country* toAttack);
    void execute() override;

private:
    Country* attacker;
    Country* toAttack;
};
