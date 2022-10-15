#include "../public/FactionState.h"

/**
 * Constructor for FactionState
 * @param countries
 */
FactionState::FactionState(std::vector<Country*> countries)
{
    this->countries = countries;
}

/**
 * Gets the countries
 * @return countries
 */
std::vector<Country*> FactionState::getCountries()
{
    return this->countries;
}

