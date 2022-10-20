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
    // int damage = t->getDMG();
    // Troops* newTroop = new Troops();
    // newTroop->setHp(damage * this->weight);
    // t = newTroop;
    // Uncommented because refernces are broken @Keelan-Matthews
    //Just look at taylas code and modify it to what it needs to do
}
