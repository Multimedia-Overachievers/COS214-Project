/*
 *  FactionState.cpp
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#include "../public/FactionState.h"

/**
 * @brief Constructor for FactionState
 * @param countries
 */
FactionState::FactionState(std::list<Country*> countries, FactionStance stance, FactionName name)
{
    this->countries = countries;
    this->stance = stance;
    this->name = name;
}

/**
 * @brief Gets the countries
 * @return countries
 */
std::list<Country*> FactionState::getCountries()
{
    return this->countries;
}

/**
 * @brief Gets the stance
 * @return stance
 */
FactionStance FactionState::getStance()
{
    return this->stance;
}

/**
 * @brief Gets the name
 * @return name
 */
FactionName FactionState::getName()
{
    return this->name;
}

/**
 * @brief Sets the stance of the faction
 * 
 */
void FactionState::setStance(FactionStance stance)
{
    this->stance = stance;
}
