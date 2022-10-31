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
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();

    if(this->owner != this->country->getOwner())
    {
        simulator->captureCountry(this->country, simulator->getFaction(this->owner));
        simulator->setLastResult(ActionResult::Win);
    }
    else if(this->country->hasTroops()){
        simulator->setLastResult(ActionResult::Loss);
    }
    else{
        simulator->setLastResult(ActionResult::Draw);
    }
}

