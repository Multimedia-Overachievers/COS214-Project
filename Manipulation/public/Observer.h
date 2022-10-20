/*
 *  Country.h
 *  Created on: 10/19/2022.
 *  Author: Francois Smith (u21649988)
 */

#pragma once

/**
 * @brief Abstract class that defines the interface for all observers
 */
class Observer
{
public:
    virtual void update() = 0;
};