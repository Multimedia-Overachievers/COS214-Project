/*
 *  Faction.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/ConcreteFaction.h"

ConcreteFaction::ConcreteFaction(ConcreteSimulator *simulator, FactionName name) 
{
    this->simulator = simulator;
    this->name = name;

    // Generate countries
    if (name == Allies)
    {
        countries.push_back(new Country(CountryName::France, name, 3, 0)); 
        countries.push_back(new Country(CountryName::UnitedKingdom, name, 2, 0));
        countries.push_back(new Country(CountryName::UnitedStates, name, 2, 1));
    }
    else
    {
        countries.push_back(new Country(CountryName::Germany, name, 0, 3));
        countries.push_back(new Country(CountryName::Italy, name, 1, 0));
        countries.push_back(new Country(CountryName::Japan, name, 2, 2));
    }

    // // @Keelan-Matthews make sure each country deletes its own buildings
    // for (int i = 0; i < numBuildings; i++)
    // {
    //     delete buildingFactory[i];
    // }
    // delete [] buildingFactory;
}


// void ConcreteFaction::reStock() {
//     // simulator->notify("reStock");
// }

// void ConcreteFaction::attack() {
//     // simulator->notify("attack");
// }

/**
 * @description Gets the current state of the faction.
 * @return FactionState
 */
FactionState* ConcreteFaction::getState() 
{
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
FactionStance ConcreteFaction::getStance() 
{
    return stance;
}

/**
 * @brief Return the name of the faction.
 * @return FactionName
 */
FactionName ConcreteFaction::getName() 
{
    return name;
}

/**
 * @brief Returns the country at the given index.
 * @param index - Index of the country.
 * @return Country*
 */
Country* ConcreteFaction::getCountry(int index) 
{
    int i = 0;
    for (Country* country : countries)
    {
        if (i == index)
        {
            return country;
        }
        i++;
    }
    return nullptr;
}

/**
 * @description Gets the number of countries in the faction.
 * @return int - Strength of the faction.
 */
int ConcreteFaction::getStrength() 
{
    return countries.size();
}
