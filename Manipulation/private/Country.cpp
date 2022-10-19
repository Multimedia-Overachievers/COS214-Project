#include "../public/CountryObserver.h"
#include "../public/Country.h"

/**
 * @brief Country::Country
 * @param name
 * @param continent
 * @param owner
 * @param troops
 */
Country::Country(string name, vector<Building *> buildings) {
    this->name = name;
    this->buildings = buildings;
    this->observer = new CountryObserver(this);
}

/**
 * @brief Checks if the country has troops
 * @return
 */
bool Country::hasTroops() {
    return !this->troops.empty();
}

/**
 * @brief Removes a troop
 * @return
 */
Troops *Country::removeTroop() {
    Troops* troop = this->troops.back();
    this->troops.pop_back();
    return troop;
}

/**
 * @brief Adds a troop
 * @param troop
 */
void Country::addTroop(Troops *troop) {
    this->troops.push_back(troop);
}

/**
 * @brief Notifies the observer of a change
 */
void Country::notify() {
    this->observer->update();
}