/*
 *  Country.cpp
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/CountryObserver.h"
#include "../public/Country.h"

/**
 * @brief Country::Country
 * @param name
 * @param continent
 * @param owner
 * @param troops
 */
Country::Country(CountryName name, Building *building1, Building *building2) {
    this->name = name;

    if (building1 != nullptr)
    {
        buildings.push_back(building1);
    }
    if (building2 != nullptr)
    {
        buildings.push_back(building2);
    }
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

/**
 * @brief Invades a country
 * @param country
 */
void Country::invade(Country *country) {
    //..
}

Country::~Country() {
    delete this->observer;
    for (auto building : buildings)
        delete building;

    for (auto troop : troops)
        delete troop;
}
