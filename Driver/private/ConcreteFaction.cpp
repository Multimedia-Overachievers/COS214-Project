/*
 *  Faction.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/ConcreteFaction.h"

ConcreteFaction::ConcreteFaction(Simulator *simulator, std::string name) {
    this->simulator = simulator;

    // Generate buildings for the countries
    int numBuildings = 2;
    auto **buildingFactory = new BuildingFactory*[numBuildings];
    for (int i = 0; i < numBuildings; i++) {
        if (i % 2 == 0) {
            buildingFactory[i] = new HospitalFactory();
        } else {
            buildingFactory[i] = new BarracksFactory();
        }

    }

    Building *hospital = buildingFactory[0]->create();
    Building *barracks = buildingFactory[1]->create();

    // Generate countries
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

    // @Keelan-Matthews make sure each country deletes its own buildings
    for (int i = 0; i < numBuildings; i++)
    {
        delete buildingFactory[i];
    }
    delete [] buildingFactory;
}

void ConcreteFaction::reStock() {
    simulator->notify("reStock");
}

void ConcreteFaction::attack() {
    simulator->notify("attack");
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
 * @description Gets the stance of the faction.
 * @return FactionStance - Stance of the faction.
 */
FactionStance Faction::getStance() {
    return stance;
}

/**
 * @description Gets the number of countries in the faction.
 * @return int - Strength of the faction.
 */
int Faction::getStrength() {
    return countries.size();
}
