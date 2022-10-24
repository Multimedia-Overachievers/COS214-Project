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

class Observer;

/**
 * @description Represents a country in the game
 */
class Country {
public:
    explicit Country(CountryName name, FactionName owner, Building *building1 = nullptr, Building *building2 = nullptr);
    bool hasTroops();
    Troops* removeTroop();
    void addTroop(Troops* troop);
    void notify();
    void invade(Country* country);
    void conquer(Country* invader); 
    ~Country();
private:
    vector<Building*> buildings;
    vector<Troops*> troops;
    CountryName name;
    FactionName owner;
    Observer* observer;


    //Tays squad->build() sets the state of the troops automatically
    Troops* troops_sized;
};
