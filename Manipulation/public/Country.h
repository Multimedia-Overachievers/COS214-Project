/*
 *  Country.h
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "../../Creation/public/Building.h"
#include "../../Creation/public/Troops.h"
#include "../../Driver/public/enums.h"
#include <iostream>
#include <vector>

class Observer;

/**
 * @description Represents a country in the game
 */
class Country {
private:
    vector<Building*> buildings;
    vector<Troops*> troops;
    CountryName name;
    Observer* observer;
public:
    Country(CountryName name, vector<Building*> buildings);
    bool hasTroops();
    Troops* removeTroop();
    void addTroop(Troops* troop);
    void notify();
    void invade(Country* country);
};
