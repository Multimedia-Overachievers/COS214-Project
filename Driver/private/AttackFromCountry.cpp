//
// Created by thoma on 10/19/2022.
//

#include "../public/AttackFromCountry.h"

AttackFromCountry::AttackFromCountry(ConcreteFaction* myFaction, Country* attacker, Country* toAttack): FactionAction(myFaction){
        this->attacker = attacker;
        this->toAttack = toAttack;
}

bool AttackFromCountry::execute() {
    attacker->invade(toAttack);
    return true;
}