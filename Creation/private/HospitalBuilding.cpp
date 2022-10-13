#include "../public/HospitalBuilding.h"

/**
 * Constructor for HospitalBuilding
 */
HospitalBuilding::HospitalBuilding() : Building() {
    this->weight = 1.3;
}

/**
 * Buffs the troops
 * @param t Troops to buff
 * @return newTroop
 */
void HospitalBuilding::buff(Troops* t) {
    int health = t->getHp();
    Troops* newTroop = Troops();
    newTroop->setHp(health * this->weight);
    t = newTroop;
}
