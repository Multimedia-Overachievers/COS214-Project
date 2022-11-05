/*
 *  TroopIterator.h
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#pragma once
#include <vector>
#include <string>
#include "./Troops.h"
/**
 * @brief The TroopIterator class
 * @details This class is used to iterate through the troops
 * This is the Iterator in the Iterator Design Pattern
 * This is an abstract class
 *
 * @author Tayla Orsmond
 * @date 11/05/2022
 *
 */
class Troops;
class Soldiers;
class TroopIterator
{
    friend class Troops;
    friend class Soldiers;

public:
    virtual ~TroopIterator();
    virtual Troops *first() = 0;
    virtual Troops *next() = 0;
    virtual bool isDone() = 0;
    virtual Troops *current() = 0;
    virtual int getIndex() = 0;

protected:
    TroopIterator();
    TroopIterator(Troops *soldiers);
    Troops *mytroops;
    int index;
};
