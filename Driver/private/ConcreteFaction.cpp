/*
 *  Faction.cpp
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#include "../public/FactionState.h"
#include "../public/ConcreteSimulator.h"
#include "../public/structs.h"
#include "../public/ConcreteFaction.h"


ConcreteFaction::~ConcreteFaction()
{
    list<Country*>::iterator it;
    for (it = this->countries.begin(); it != this->countries.end(); ++it)
    {
        if ((*it) != nullptr)
        {
            delete *it;
        }
    }

    delete this->stance;
    delete this->observer;
}

ConcreteFaction::ConcreteFaction(FactionName name)
{   
    this->name = name;
    this->stance = new NeutralState(50);
}

/**
 * @brief Instantiates the countries for the faction.
 */
void ConcreteFaction::createCountries()
{
    if(this->name == Allies)
    {
        countries.push_back(new Country(CountryName::France, name, 3, 0, 27, false)); 
        countries.push_back(new Country(CountryName::UnitedKingdom, name, 2, 1, 30, false));
        countries.push_back(new Country(CountryName::UnitedStates, name, 0, 3, 35, false));
        countries.push_back(new Country(CountryName::SovietUnion, name, 1, 2, 40, false));
        countries.push_back(new Country(CountryName::Belgium, name, 2, 0, 16, false));
        countries.push_back(new Country(CountryName::Netherlands, name, 1, 1, 21, false));
    }
    else
    {
        countries.push_back(new Country(CountryName::Germany, name, 0, 3, 40, false));
        countries.push_back(new Country(CountryName::Italy, name, 2, 1, 27, false));
        countries.push_back(new Country(CountryName::Japan, name, 1, 2, 35, false));
        countries.push_back(new Country(CountryName::Romania, name, 1, 1, 25, false));
        countries.push_back(new Country(CountryName::Hungary, name, 2, 0, 23, false));
        countries.push_back(new Country(CountryName::Bulgaria, name, 0, 2, 22, false));
    }
}

/**
 * @brief Gets the current data of the faction.
 * @return FactionStore
 */
FactionStore* ConcreteFaction::getData() 
{
    // cout output all the current countries
    list<Country*>::iterator it;
    for (it = this->countries.begin(); it != this->countries.end(); ++it)
    {
        // output current country address
        cout << "Country: " << *it << endl;
        cout << "Country Name: " << convert_country[(*it)->getName()] << endl;
    }

    std::list<Country*> countries;
    for (Country* country : this->countries)
    {
        countries.push_back(country->clone());
        std::cout << "troop count" << countries.back()->getNumTroops() << std::endl;
    }

    // cout output all the new countries
    for (it = countries.begin(); it != countries.end(); ++it)
    {
        // output new country address
        cout << "Country2: " << *it << endl;
        cout << "Country2 Name: " << convert_country[(*it)->getName()] << endl;
        cout << "Owner: " << convert_faction[(*it)->getOwner()] << endl;
    }


    FactionStore* store = new FactionStore();
    store->countries = countries;
    store->name = this->name;
    store->stance = this->stance->clone();
    return store;
}

/**
 * @brief Sets the data of the faction.
 * @param store FactionStore
 */
void ConcreteFaction::setData(FactionStore* store)
{
    // cout output all the current countries
    list<Country*>::iterator it;
    for (it = this->countries.begin(); it != this->countries.end(); ++it)
    {
        // output current country address
        cout << "OUT Country: " << *it << endl;
        cout << "OUT Country Name: " << convert_country[(*it)->getName()] << endl;
    }

    std::cout << "Setting data for faction: " << store->name << std::endl;
    // replace old countries with new ones
    std::list<Country*> oldCountries = this->countries;
    this->countries = store->countries;

    
    // cout output all the new countries
    for (it = this->countries.begin(); it != this->countries.end(); ++it)
    {
        // output new country address
        cout << "OUT Country2: " << *it << endl;
        cout << "OUT Country2 Name: " << convert_country[(*it)->getName()] << endl;
        cout << "Owner: " << convert_faction[(*it)->getOwner()] << endl;
    }
    
    // delete old countries which are no longer needed
    for (Country* country : oldCountries)
    {
        delete country;
    }

    // push the new countries to the simulator
    for (Country* country : this->countries)
    {
        ConcreteSimulator::getInstance()->countries.push_back(country);
    }
    
    // Delete old stance
    delete this->stance;
    std::cout << "Deleted old stance" << std::endl;

    this->countries = store->countries;
    this->name = store->name;
    this->stance = store->stance;
    std::cout << "Set new data69" << std::endl;
    std::cout << this->stance;
     std::cout << this->stance->getStanceType() << std::endl;
    std::cout << "Set new data" << std::endl;
}

/**
 * @brief Gets the object stance of the faction.
 * @return FactionStance - Stance of the faction.
 */
FactionState* ConcreteFaction::getStance() 
{
    return stance;
}

/**
 * @brief Returns the actual type of the stance
 * 
 * @return StanceType 
 */
StanceType ConcreteFaction::getStanceType()
{
    return this->stance->getStanceType();
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
    std::cout << "Removing country: " << convert_country[country->getName()] << std::endl;
    countries.remove(country);
    // print all the countries
    list<Country*>::iterator it;
    for (it = this->countries.begin(); it != this->countries.end(); ++it)
    {
        // output current country address
        cout << "Removed ?? Country: " << *it << endl;
        cout << "Removed ?? Country Name: " << convert_country[(*it)->getName()] << endl;
    }
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
void ConcreteFaction::changeState(ActionResult result)
{
    this->stance->handleState(result, this);
}

/**
 * @brief Set the current stance to the one passed in as a parameter; will be most often used by FactionState.cpp
 * 
 * @param stance 
 */
void ConcreteFaction::setStance(FactionState* stance)
{
    delete(this->stance);
    this->stance = stance;
}

/**
 * @brief Returns the total number of troops from every country in a faction
 * 
 * @return int 
 */
int ConcreteFaction::getTotalTroops()
{
    std::cout << "Getting total troops" << std::endl;
    int total = 0;
    list<Country*>::iterator it;
    for (it = this->countries.begin(); it != this->countries.end(); ++it)
    {
        if ((*it) != nullptr)
        {
            total += (*it)->getNumTroops();
        }
    }
    return total;
}

/**
 * @brief A function used to clone the faction
 * 
 * @return Faction* 
 */
Faction* ConcreteFaction::clone()
{
    return new ConcreteFaction(this);
}

ConcreteFaction::ConcreteFaction(Faction* faction)
{
    // copy name
    this->name = faction->getName();

    // copy countries
    list<Country*>::iterator it;
    for (it = faction->countries.begin(); it != faction->countries.end(); ++it)
    {
        if ((*it) != nullptr)
        {
            this->countries.push_back((*it)->clone());
        }
    }

    // copy state
    FactionState* stateObj = nullptr;
    StanceType stateType = faction->getStance()->getStanceType();
    int stateMorale = faction->getStance()->getMorale();
    switch (stateType)
    {
        case DefensiveStance:
            stateObj = new DefensiveState(stateMorale);
            break;

        case AggressiveStance:
            stateObj = new AggressiveState(stateMorale);
            break;

        case NeutralStance:
            stateObj = new NeutralState(stateMorale);
            break;
        
        default:
            stateObj = new NeutralState(stateMorale);
            break;
    }

    // copy observer
    FactionObserver* obsObj = new FactionObserver(this);
}