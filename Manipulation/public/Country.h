/*
 *  Country.h
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


#include "../../Creation/public/Building.h"
#include "../../Creation/public/Troops.h"
#include "../../Driver/public/ConcreteFaction.h"
#include "Observer.h"
#include <iostream>
#include <vector>

/**
 * @description Represents a country in the game
 */
class Country {
private:
    vector<Building*> buildings;
    vector<Troops*> troops;
    string name;
    Observer* observer;
public:
    Country(string name, vector<Building*> buildings);
    void attach(Observer* observer);
    void detach(Observer* observer);
    bool hasTroops();
    Troops* removeTroop();
    void addTroop(Troops* troop);
    void notify();
};
