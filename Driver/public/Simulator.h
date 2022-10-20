/*
 *  Simulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once 
#include <string>
#include <iostream>

class Simulator
{
public:
    virtual void notify(std::string command) = 0;
};
