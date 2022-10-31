/*
 *  FactionObserver.cpp
 *  Created on: 10/27/2022.
 *  Author: Francois Smith (u21649988)
 */

#include "../../Driver/public/ConcreteSimulator.h"
#include "../../Driver/public/ConcreteFaction.h"
#include "../public/FactionObserver.h"

FactionObserver::FactionObserver(ConcreteFaction* faction)
{
    this->faction = faction;
    //this->stance = this->faction->getStance();
}

/**
 * @brief Checks the new state of the faction and sends relevant data to simulation
 */
void FactionObserver::update()
{
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();
    this->faction->changeState(simulator->getLastResult(), simulator->getOpposite(this->faction));
}