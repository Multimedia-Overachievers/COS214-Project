/*
 *  Troops.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/Troops.h"

Troops::Troops(Name name, State state){
    this->name = name;
    this->state = state;
}

Troops::Troops(Name name){
    this->name = name;
    this->state = Ready;
}

Troops::~Troops(){
}

