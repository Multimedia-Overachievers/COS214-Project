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
Troops BarracksBuilding::buff(Troops* t) {
    int damage = t->getDmg();
    Troops* newTroop = Troops();
    newTroop->setHp(damage * this->weight);
    t = newTroop;
}
