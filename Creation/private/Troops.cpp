/*
 *  Troops.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/Troops.h"

Troops::Troops(NAME name, STATE state){
    this->name = name;
    this->state = state;
}

Troops::Troops(NAME name){
    this->name = name;
    this->state = READY;
}

Troops::~Troops(){
}

