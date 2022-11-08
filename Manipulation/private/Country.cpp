/*
 *  Country.cpp
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 *  Edited by: Tayla Orsmond (u21467456)
 */

#include "../../Driver/public/ConcreteSimulator.h"
#include "../public/CountryObserver.h"
#include "../../Driver/public/MoveTroops.h"
#include "../public/Country.h"


/**
 * @brief Country::Country
 * @param name - name of the country
 * @param continent - the continent the country is in
 * @param owner - the faction that owns the country
 * @param hospitals - number of hospitals in the country
 * @param barracks - number of barracks in the country
 */
Country::Country(CountryName name, FactionName owner, int hospitals, int barracks, int startingTroops)
{
    this->name = name;
    this->owner = owner;

    buildings.insert(pair<Building, int>(Hospital, hospitals));
    buildings.insert(pair<Building, int>(Barracks, barracks));

    ConcreteSimulator::getInstance()->countries.push_back(this);
    this->observer = new CountryObserver(this);
    this->myTroops = new Soldiers();

    this->addTroops(startingTroops);
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
    if(this->myTroops == nullptr)
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
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    std::string faction(convert_faction[this->owner]);
    std::cout << "FACTION: " << faction << std::endl;
    std::string myName(convert_country[this->name]);
    std::cout << "MY NAME: " << myName << std::endl;
    std::string countryName(convert_country[country->getName()]);
    simulator->messageMap["Action"] = "The " + faction + " have invaded " + countryName + " from " + myName + ". ";

    int attackingTroops = this->myTroops->getTotalTroops();
    std::cout << "ATTACKING TROOPS: " << attackingTroops << std::endl;
    int defendingTroops = country->myTroops->getTotalTroops();
    std::cout << "DEFENDING TROOPS: " << defendingTroops << std::endl;

    if (country->hasTroops())
    {   
        int damage = this->buffDMG();            // Get damage from my troops
        int invaderHealth = this->buffDefence(); // Get health from my troops
        int defence = country->buffDMG();        // Get damage from enemy troops
        int defenderHealth = country->buffDefence(); // Get health from enemy troops
        std::cout << "THIS FAR" << std::endl;
        while (invaderHealth > 0 && defenderHealth > 0)
        {
            defenderHealth = country->takeDMG(damage); // Take damage from my troops
            if (defenderHealth > 0)
            {
                invaderHealth = this->takeDMG(defence); // Take damage from enemy troops
            }
        }
        if (defenderHealth <= 0)
        { // I win if their health is 0 or less
            country->getConqueredBy(this);
            simulator->messageMap["Result"] = "They won the battle, inflicting " + std::to_string(defendingTroops) + " casualties, suffering " + std::to_string(attackingTroops - this->myTroops->getTotalTroops()) + " of their " + std::to_string(attackingTroops) + ". " + countryName + " now belongs to the " + faction + ". ";
            // move half of my troops to the country
            FactionAction* moveAction = new MoveTroops(simulator->getFaction(this->owner), country, this, (this->myTroops->getTotalTroops() / 2));
            simulator->action(moveAction);
        }
        else if (invaderHealth <= 0)
        { // They win if my health is 0 or less
            // country->getConqueredBy(this);
            simulator->messageMap["Result"] = "They lost the battle, losing " + std::to_string(attackingTroops) + " troops. The defenders suffered " + std::to_string(defendingTroops - country->myTroops->getTotalTroops()) + " of their " + std::to_string(defendingTroops) + " troops. ";
        }
        std::cout << "END OF BATTLE" << std::endl;
    }
    else
    {
        country->getConqueredBy(this);
    }

    std::cout << "END OF INVADE" << std::endl;
    country->notify();
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
void Country::getConqueredBy(Country *invader)
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
        int troops = this->myTroops->getTotalTroops();
        return troops;
    }
    else
    {
        return 0;
    }
}



map<Building, int> Country::getBuildings()
{
    return this->buildings;
}

/**
 * @brief Clone a country object
 * 
 * @return Country* 
 */
Country* Country::clone()
{
    Country* country = new Country(this->name, this->owner, this->buildings[Hospital], this->buildings[Barracks], this->getNumTroops());
    country->observer = new CountryObserver(this);
    return country;
}
