/*
 *  BarracksBuilding.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/BarracksBuilding.h"

/**
 * Constructor for BarracksBuilding
 */
BarracksBuilding::BarracksBuilding() : Building() {
    this->weight = 1.5;
}

/**
 * Buffs the troops
 * @param t Troops to buff
 * @return newTroop
 */
void BarracksBuilding::buff(Troops* t) {
    int damage = t->getTotalDMG();
    t->buffDMG(damage * this->weight);
}
