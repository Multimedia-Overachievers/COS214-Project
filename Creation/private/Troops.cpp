/*
 *  Troops.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/Troops.h"

Troops::Troops(NAME name = SQUAD, STATE state = READY) //ctor
{
    this->name = name;
    this->state = state;
}

Troops::~Troops() = default; //dtor

