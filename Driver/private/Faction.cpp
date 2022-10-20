/*
 *  Faction.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/Faction.h"
#include "../public/enums.h"
#include "../../Creation/public/BuildingFactory.h"

Faction::Faction(Simulator *simulator, std::string name) {
    this->simulator = simulator;

    // use the factory to make buildings @Dhairiya
    BuildingFactory *buildingFactory = new BuildingFactory();
    Building *hospital = buildingFactory->create();
    Building *barracks = buildingFactory->create();


    if (name == "Allies")
    {
        countries.push_back(new Country(CountryName::France, hospital, hospital));
        countries.push_back(new Country(CountryName::UnitedKingdom, barracks));
        countries.push_back(new Country(CountryName::UnitedStates, barracks, hospital));
    }
    else if (name == "Axis")
    {
        countries.push_back(new Country(CountryName::Germany, hospital, hospital));
        countries.push_back(new Country(CountryName::Italy, hospital));
        countries.push_back(new Country(CountryName::Japan, barracks, hospital));
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