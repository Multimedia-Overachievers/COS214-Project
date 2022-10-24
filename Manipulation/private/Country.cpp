/*
 *  Country.cpp
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/CountryObserver.h"
#include "../public/Country.h"
#include "../../Creation/public/Squad.h"

/**
 * @brief Country::Country
 * @param name
 * @param continent
 * @param owner
 * @param troops
 */
Country::Country(CountryName name, FactionName owner, Building *building1, Building *building2) {
    this->name = name;
    this->owner = owner;

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
    //call build on using the troops array
    this->troops.push_back(troop);
    Squad* s = new Squad(troop->getName(), troop->getState());
    s->build(this->troops);
    this->troops_sized = s;
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
    
    // -?Ross- Ask Tay about getting buffs 
    if (country->hasTroops()) 
    {
        int damage = this->troops_sized->getTotalDMG();   // Get damage from my troops
        int defence = country->troops_sized->getTotalDMG(); // Get damage from enemy troops

        int invaderHealth = this->troops_sized->getTotalHP(); // Get health from my troops
        int defenderHealth = country->troops_sized->getTotalHP(); // Get health from enemy troops

        // -?Ross- Ask group about retreating from battle
        bool callOff = false;
        do
        {
            invaderHealth -= defence;
            defenderHealth -= damage;
        } while ((invaderHealth > 0 && defenderHealth > 0) && !callOff);

        if (defenderHealth <= 0) 
        {
            country->troops.clear(); // Remove all enemy troops
            this->conquer(country);  // Conquer the country
        } 
        else if (invaderHealth <= 0) 
        {
            this->troops.clear(); // Remove all my troops
        }
        else if (callOff)
        {
            
        }

        this->notify();

    }

}

/**
 * @brief Changes the owner of the country to the invader
 * @param invader
 */
void Country::conquer(Country *invader) {
    this->owner = invader->owner;
}

Country::~Country() {
    delete this->observer;
    for (auto building : buildings)
        delete building;

    for (auto troop : troops)
        delete troop;

    delete troops_sized;
}
