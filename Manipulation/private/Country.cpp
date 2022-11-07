/*
 *  Country.cpp
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 *  Edited by: Tayla Orsmond (u21467456)
 */

#include "../../Driver/public/ConcreteSimulator.h"
#include "../public/CountryObserver.h"
#include "../public/Country.h"

/**
 * @brief Country::Country
 * @param name - name of the country
 * @param continent - the continent the country is in
 * @param owner - the faction that owns the country
 * @param hospitals - number of hospitals in the country
 * @param barracks - number of barracks in the country
 */
Country::Country(CountryName name, FactionName owner, int hospitals, int barracks)
{
    this->name = name;
    this->owner = owner;

    buildings.insert(pair<Building, int>(Hospital, hospitals));
    buildings.insert(pair<Building, int>(Barracks, barracks));

    ConcreteSimulator::getInstance()->countries.push_back(this);
    this->observer = new CountryObserver(this);
    this->myTroops = nullptr;
}

/**
 * @brief Checks if the country has troops
 * @return - true if the country has troops, false otherwise
 */
bool Country::hasTroops()
{
    return this->myTroops != nullptr && this->myTroops->getTotalTroops() > 0;
}

/**
 * @brief Removes all the troops from the country
 * @warning Any memory passed back is your problem now, so make sure to delete it when you are done with it
 *
 * @return - a vector of troops that were removed
 */
vector<Troops *> Country::removeAllTroops()
{
    return this->myTroops->disband();
}

/**
 * @brief Removes a number of Troops from the country
 * @warning Any memory passed back is your problem now, so make sure to delete it when you are done with it
 *
 * @return vector of Troops that were removed from the country
 */
vector<Troops *> Country::removeTroops(int noToRemove)
{
    return this->myTroops->disband(noToRemove);
}

/**
 * @brief Adds a troop to the country
 * @note Assume any memory you pass to the troop will be automatically deleted by the troop
 *
 * @param troop - a vector of troops to add (memory is self managed)
 */
void Country::addTroops(vector<Troops *> troops)
{
    if (this->myTroops == nullptr)
    {
        this->myTroops = new Soldiers();
    }
    this->myTroops->build(troops);
}

/**
 * @brief Adds a troop to the country
 * @note Assume any memory you pass to the troop will be automatically deleted by the troop
 *
 * @param troop - the troop * to add (memory is self managed)
 */
void Country::addTroops(Troops *troop)
{
    if (this->myTroops == nullptr)
    {
        this->myTroops = new Soldiers();
    }
    this->myTroops->build(troop);
}

/**
 * @brief Adds a troop to the country
 * @note Assume any memory you pass to the troop will be automatically deleted by the troop
 *
 * @param noToAdd - the no of troops to add (memory is self managed)
 */
void Country::addTroops(int noToAdd)
{
    if (this->myTroops == nullptr)
    {
        this->myTroops = new Soldiers();
    }
    this->myTroops->build(noToAdd);
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
    std::cout << "Invading " << country->getName() << std::endl;
    if (country->hasTroops())
    {
        int damage = this->buffDMG();            // Get damage from my troops
        int invaderHealth = this->buffDefence(); // Get health from my troops

        int defence = country->buffDMG();            // Get damage from enemy troops
        int defenderHealth = country->buffDefence(); // Get health from enemy troops

        while (invaderHealth > 0 && defenderHealth > 0)
        {
            defenderHealth = country->takeDMG(damage); // Take damage from my troops
            if (defenderHealth > 0)
            {
                invaderHealth = this->takeDMG(defence); // Take damage from enemy troops
            }
            std::cout << "Invader Health: " << invaderHealth << std::endl;
            std::cout << "Defender Health: " << defenderHealth << std::endl;
        }
        if (defenderHealth <= 0)
        { // I win if their health is 0 or less
            this->conquer(country);
            std::cout << "I win" << std::endl;
        }
        else if (invaderHealth <= 0)
        { // They win if my health is 0 or less
            country->conquer(this);
            std::cout << "You lost the battle" << std::endl;
        }
    }
    else
    {
        std::cout << "You won the battle (The enemy had no troops)" << std::endl;
        this->conquer(country);
   
    }

    std::cout << "notifying" << std::endl;
    this->notify();
}

/**
 * @brief Takes damage from an attack
 * @param damage - the damage to take
 * @return - the health left after taking damage
 */
int Country::takeDMG(int damage)
{
    return this->myTroops->takeDMG(damage);
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
    delete this->myTroops;
}

/**
 * @brief Buffs the damage of the troops using the number of barracks. 5% per barracks
 * @param damage
 * @return - the buffed damage
 */
int Country::buffDMG()
{
    int damage = this->myTroops->getTotalDMG();
    return damage + (damage * (buildings[Barracks] * 0.05));
}

/**
 * @brief Buffs the defence of the troops using the number of hospitals. 5% per hospital
 * @param defence
 * @return - the buffed defence
 */
int Country::buffDefence()
{
    int defence = this->myTroops->getTotalHP();
    return defence + (defence * (buildings[Hospital] * 0.05));
}

/**
 * @brief Returns the total number of troops a country has
 * @return int
 */
int Country::getNumTroops()
{
    if (this->myTroops != nullptr)
    {
        return this->myTroops->getTotalTroops();
    }
    else
    {
        return 0;
    }
}