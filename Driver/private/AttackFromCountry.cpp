//
// Created by thomas on 10/19/2022.
//

#include "../public/AttackFromCountry.h"
#include "../../Manipulation/public/Country.h"

AttackFromCountry::AttackFromCountry(ConcreteFaction* myFaction, Country* attacker, Country* toAttack): FactionAction(myFaction){
    this->attacker = attacker;
    this->toAttack = toAttack;
}

void AttackFromCountry::execute() {
    attacker->invade(toAttack);
}