/*
 *  Faction.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/ConcreteFaction.h"

ConcreteFaction::ConcreteFaction(FactionName name)
{   
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
}

/**
 * @brief Gets the current data of the faction.
 * @return FactionStore
 */
FactionStore* ConcreteFaction::getData() 
{
    std::list<Country*> countries;
    for (Country* country : this->countries)
    {
        countries.push_back(country);
    }
    
    FactionStore* store = new FactionStore();
    store->countries = countries;
    store->name = this->name;
    store->stance = this->stance;
    return store;
}

/**
 * @brief Gets the stance of the faction.
 * @return FactionStance - Stance of the faction.
 */
FactionState* ConcreteFaction::getStance() 
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
 * @brief Gets the number of countries in the faction.
 * @return int - Strength of the faction.
 */
int ConcreteFaction::getStrength() 
{
    return countries.size();
}



/**
 * @brief Removes a country from the faction.
 * @param country - Country to remove.
 */
void ConcreteFaction::removeCountry(Country* country)
{
    countries.remove(country);
}

/**
 * @brief Adds a country to the faction.
 * @param country - Country to add.
 */
void ConcreteFaction::addCountry(Country* country)
{
    countries.push_back(country);
}

/**
 * @brief Notifies the observer of the faction.
 */
void ConcreteFaction::notify()
{
    observer->update();
}

/**
 * @brief Changes the current state of the faction.
 * 
 */
void ConcreteFaction::changeState(ActionResult result, Faction* opposite = nullptr)
{
    // get the current state
    // if defensive, morale == 33, if neutral, morale == 67, if aggressive, morale == 100

}