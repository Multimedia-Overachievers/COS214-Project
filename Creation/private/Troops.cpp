#include "Troops.h"

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

