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
    this->owner = country->getOwner();
}

/**
 * @brief Checks the new state of the country and sends relevant data to simulation
 */
void CountryObserver::update()
{
    if(this->owner != this->country->getOwner())
    {
        ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
        simulator->captureCountry(this->country, simulator->getFaction(this->owner));
    }
}

