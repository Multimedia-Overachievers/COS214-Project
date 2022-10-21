/*
 *  BarracksFactory.cpp
 *  Created on: 10/21/2022.
 *  Author: Dhairiya Chhipa (u21437841)
 */

#include "../public/BarracksFactory.h"

/**
 * @brief Construct a new Barracks Factory:: Barracks Factory object
 * 
 */
BarracksFactory::BarracksFactory() {};

/**
 * @brief Destroy the Barracks Factory:: Barracks Factory object
 * 
 */
BarracksFactory::~BarracksFactory() {};

/**
 * @brief factoryMethod() used to create a HospitalBuilding object
 * 
 * @return Building* 
 */
Building* BarracksFactory::createBuilding()
{
    return new BarracksBuilding();
}