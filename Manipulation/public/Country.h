/*
 *  Country.h
 *  Created on: 10/19/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "../../Creation/public/Troops.h"
#include "../../Driver/public/enums.h"
#include "../../Creation/public/Soldiers.h"
#include <iostream>
#include <map>

class CountryObserver;

/**
 * @description Represents a country in the game
 */
class Country
{
public:
    friend class Restock;
    Country(CountryName name, FactionName owner, int hospitals, int barracks);
    ~Country();
    bool hasTroops();
    vector<Troops *> removeAllTroops();
    vector<Troops *> removeTroops(int noToRemove);
    void addTroops(Troops *troops);
    void addTroops(vector<Troops *> troops);
    void addTroops(int noToAdd);
    void notify();
    void invade(Country *country);
    int takeDMG(int dmg);
    void conquer(Country *country);
    int buffDMG();
    int buffDefence();
    int getNumTroops();

    FactionName getOwner() { return this->owner; };
    void setOwner(FactionName owner) { this->owner = owner; };
    CountryName getName() { return this->name; };

private:
    map<Building, int> buildings;
    CountryName name;
    FactionName owner;
    CountryObserver *observer;
    Troops * myTroops;
};
