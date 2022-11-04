/*
 *  Country.cpp
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../../Driver/public/ConcreteSimulator.h"
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
Country::Country(CountryName name, FactionName owner, int hospitals, int barracks) 
{
    this->name = name;
    this->owner = owner;

    buildings.insert(pair<Building, int>(Hospital, hospitals));
    buildings.insert(pair<Building, int>(Barracks, barracks));
    
    ConcreteSimulator::getInstance()->countries.push_back(this);
    this->observer = new CountryObserver(this);
}

/**
 * @brief Checks if the country has troops
 * @return
 */
bool Country::hasTroops() 
{
    return !this->troops.empty();
}

/**
 * @brief Removes a troop
 * @return
 */
Troops *Country::removeTroop() 
{
    Troops* troop = this->troops.back();
    this->troops.pop_back();
    return troop;
}

/**
 * @brief Adds a troop
 * @param troop
 */
void Country::addTroop(Troops* troop) 
{
    //call build on using the troops array
    this->troops.push_back(troop);
    Squad* s = new Squad(troop->getName(), troop->getState());
    s->build(this->troops);
    this->troops_sized = s;
}

/**
 * @brief Notifies the observer of a change
 */
void Country::notify() 
{
    this->observer->update();
}

/**
 * @brief Invades a country
 * @param country
 */
void Country::invade(Country *country) 
{
    if(country->hasTroops()) 
    {
        int damage = this->buffDMG(this->troops_sized->getTotalDMG());   // Get damage from my troops
        int defence = country->buffDMG(country->troops_sized->getTotalDMG()); // Get damage from enemy troops

        int invaderHealth = this->buffDefence(this->troops_sized->getTotalHP()); // Get health from my troops
        int defenderHealth = country->buffDefence(country->troops_sized->getTotalHP()); // Get health from enemy troops
        do
        {
            invaderHealth -= defence;
            defenderHealth -= damage;
        } while ((invaderHealth > 0 && defenderHealth > 0));

        if (defenderHealth <= 0) 
        {
            this->conquer(country);  // Conquer the country
        }
        
        this->troops_sized->takeDMG(country->troops_sized->getTotalHP() - invaderHealth);
        country->troops_sized->takeDMG(this->troops_sized->getTotalHP() - defenderHealth);
    }
    else{
        this->conquer(country);
    }

    this->notify();
}

/**
 * @brief Changes the owner of the country to the invader
 * @param invader
 */
void Country::conquer(Country *invader) 
{
    setOwner(invader->owner);
}

Country::~Country() 
{
    delete this->observer;

    for (auto troop: troops)
        delete troop;

    delete troops_sized;
}

/**
 * @brief Buffs the damage of the troops using the number of barracks. 5% per barracks
 * @param damage
 * @return
 */
int Country::buffDMG(int damage) {
    return damage + (damage * (buildings[Barracks] * 0.05));
}

/**
 * @brief Buffs the defence of the troops using the number of hospitals. 5% per hospital
 * @param defence
 * @return
 */
int Country::buffDefence(int defence) {
    return defence + (defence * (buildings[Hospital] * 0.05));
}