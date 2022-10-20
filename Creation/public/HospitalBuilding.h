/*
 *  HospitalBuilding.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "Building.h"

/**
 * @description Hospital building
 */
class HospitalBuilding : public Building {
public:
    HospitalBuilding();
    void buff(Troops* t) override;
};
