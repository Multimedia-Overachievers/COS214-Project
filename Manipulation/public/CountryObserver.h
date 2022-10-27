/*
 *  CountryObserver.h
 *  Created on: 10/19/2022.
 *  Author: Francois Smith (u21649988)
 */

#pragma once
#include "./Observer.h"
#include "../../Driver/public/ConcreteSimulator.h"

//Forward declaration to avoid circular dependency
class Country;

class CountryObserver: public Observer
{
public:
    CountryObserver(Country* country);
    void update() override;

private:
    Country* country;
    FactionName owner;
};