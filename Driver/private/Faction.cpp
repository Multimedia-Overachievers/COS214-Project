/*
 *  Faction.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/Faction.h"
#include "../public/enums.h"

Faction::Faction(Simulator *simulator, std::string name) {
    this->simulator = simulator;
    std::vector<Building*> buildings;


    if (name == "Allies")
    {
        countries.push_back(new Country(CountryName::France, buildings));
        countries.push_back(new Country(CountryName::UnitedKingdom, buildings));
        countries.push_back(new Country(CountryName::UnitedStates, buildings));
    }
    else if (name == "Axis")
    {
        countries.push_back(new Country(CountryName::Germany, buildings));
        countries.push_back(new Country(CountryName::Italy, buildings));
        countries.push_back(new Country(CountryName::Japan, buildings));
    }
    else
    {
        std::cout << "Invalid faction name" << std::endl;
    }
}

void Faction::attack() {
    simulator->notify("attack");
}

void Faction::reStock() {
    simulator->notify("reStock");
}

/**
 * @description Gets the current state of the faction.
 * @return FactionState
 */
FactionState* Faction::getState() {
    std::vector<Country*> countries;
    for (Country* country : this->countries)
    {
        countries.push_back(country);
    }
    return new FactionState(countries);
}

/**
 * @description Gets the number of countries in the faction.
 * @return int - Strength of the faction.
 */
int Faction::getStrength() {
    return countries.size();
}

/**
 * @description Gets the stance of the faction.
 * @return FactionStance - Stance of the faction.
 */
FactionStance Faction::getStance() {
    return stance;
}