/*
 *  FactionAction.h
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once
#include <string>
#include <iostream>

class Faction;

class FactionAction
{
public:
    explicit FactionAction(Faction* c);
    Faction* getFaction();
    virtual void execute() = 0;

protected:
    Faction* myFaction;

//DEBUG_
public:
    std::string type;
    void print(){std::cout << "Action: " << type << std::endl;}
};