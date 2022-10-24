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
            // Remove a percentage of troops from either side
            Country* removeFrom = this; // First the Invader's loss
            for(int i = 0; i < 2; i++) 
            {
                int loss = removeFrom->troops_sized->getTotalHP() - invaderHealth; // First the Invader's loss
                while(loss > 0) // While the faction has squads to lose
                { 
                    if(loss > 500) // Remove an ARMY
                    {
                        // Remove an army
                        loss -= 500;
                    }
                    else if(loss > 400) // Remove a BATTALION
                    {
                        // Remove a battalion
                        loss -= 400;
                    }
                    else if(loss > 300) // Remove a COMPANY
                    {
                        // Remove a company
                        loss -= 300;
                    }
                    else if(loss > 200) // Remove a PLATOON
                    {
                        // Remove a platoon
                        loss -= 200;
                    }
                    else if(loss > 100) // Remove a SQUAD
                    {
                        // Remove a squad
                        loss -= 100;
                    }
                    else // Damage a single squad
                    {
                        // Damage a single squad
                        loss = 0;
                    }

                }
                removeFrom = country; // Then the Defender's loss
            }
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
