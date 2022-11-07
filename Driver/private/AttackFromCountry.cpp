/*
 *  AttackFromCountry.cpp
 *  Created on: 10/19/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#include "../public/AttackFromCountry.h"
#include "../../Manipulation/public/Country.h"

/**
* @brief Constructor for the AttackFromCountry command
* @param myFaction The faction to be built in (passed to FactionAction)
* @param attacker The country that is attacking.
* @param toAttack The country to be attacked.
*/
AttackFromCountry::AttackFromCountry(Faction* myFaction, Country* attacker, Country* toAttack): FactionAction(myFaction)
{
    this->attacker = attacker;
    this->toAttack = toAttack;
    this->action = ActionType::AttackAction;
}

/**
 * @brief Calls invade on the one country to attack the other
 */
void AttackFromCountry::execute()
{
    std::cout << convert_country[attacker->getName()] << " is attacking " << convert_country[toAttack->getName()] << std::endl;
    attacker->invade(toAttack);
}