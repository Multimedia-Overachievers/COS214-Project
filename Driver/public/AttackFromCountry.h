#pragma once
#include "FactionAction.h"
#include "ConcreteFaction.h"

class AattackFromCountry: public FactionAction {
private:
    Country* attacker;
    Country* toAttack;
    ConcreteFaction* myFaction;
public:
    AattackFromCountry(ConcreteFaction* myFaction, Country* attacker, Country* toAttack): FactionAction(myFaction) {
        this->attacker = attacker;
        this->toAttack = toAttack;
    }

    virtual bool execute() {
        attacker->invade(toAttack);
    }
};
