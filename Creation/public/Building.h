/*
 * Building.h
 *
 *  Created on: 10/13/2022.
 *      Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "./Troops.h"

/**
 * @brief Abstract class for all buildings
 */
class Building {
public:
    virtual void buff(Troops* t) = 0;
    
protected:
    double weight;
};