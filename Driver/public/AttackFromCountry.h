#pragma once
#include "FactionAction.h"
#include "ConcreteFaction.h"

class AttackFromCountry: public FactionAction {
private:
    Country* attacker;
    Country* toAttack;
public:
    AttackFromCountry(ConcreteFaction* myFaction, Country* attacker, Country* toAttack);
    virtual bool execute();
};
