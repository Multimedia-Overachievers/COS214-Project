//
// Created by thomas on 10/19/2022.
//

#include "../public/AttackFromCountry.h"
#include "../../Manipulation/public/Country.h"

/**
* @brief Constructor for the AttackFromCountry command
* @param myFaction The faction to be built in (passed to FactionAction)
* @param attacker The country that is attacking.
* @param toAttack The country to be attacked.
*/
AttackFromCountry::AttackFromCountry(ConcreteFaction* myFaction, Country* attacker, Country* toAttack): FactionAction(myFaction){
    this->attacker = attacker;
    this->toAttack = toAttack;
}

/**
 * @brief Calls invade on the one country to attack the other
 */
void AttackFromCountry::execute() {
    attacker->invade(toAttack);
}