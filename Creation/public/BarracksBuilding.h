/*
 *  BarracksBuilding.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "Building.h"
#include "../public/Troops.h"

/**
 * @brief BarracksBuilding class
 *
 */
class BarracksBuilding : public Building {
public:
    BarracksBuilding();
    void buff(Troops* t) override;
};
