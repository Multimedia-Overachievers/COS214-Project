/*
 *  TroopIterator.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/TroopIterator.h"

TroopIterator::TroopIterator() = default;

TroopIterator::TroopIterator(Troops * soldiers)
{
    index = 0;
    mytroops = soldiers;
}

TroopIterator::~TroopIterator(){
    index = 0;
    mytroops = nullptr;
}
