/*
 *  CountryObserver.cpp
 *  Created on: 10/19/2022.
 *  Author: Francois Smith (u21649988)
 */

#include "../public/Country.h"
#include "../public/CountryObserver.h"

CountryObserver::CountryObserver(Country* country)
{
    this->country = country;
}

/**
 * @brief Checks the new state of the country and sends relevant data to simulation
 */
void CountryObserver::update()
{
    std::cout << "Country has been updated" << std::endl;
}

