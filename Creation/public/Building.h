/*
 * Building.h
 *
 *  Created on: 10/13/2022.
 *      Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "./Troops.h"

/**
 * @description Abstract class for all buildings
 */
class Building {
protected:
    double weight;
public:
    virtual Troops buff(Troops t) = 0;
};