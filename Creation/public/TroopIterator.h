//Tayla Orsmond u21467456
#pragma once
#include <vector>
#include <string>

/**
 * @brief The TroopIterator class
 * @details This class is used to iterate through the troops
 * This is the Iterator in the Iterator Design Pattern
 * This is an abstract class
 * 
 * @author Tayla Orsmond
 * @date 10/19/2022
 * 
 */
class Troops;
class TroopIterator{
    public:
        virtual ~TroopIterator();
        virtual Troops * first() = 0;
        virtual Troops * next() = 0;
        virtual bool isDone() = 0;
        virtual Troops* current() = 0;
        virtual vector<Troops *>::iterator at() = 0;
    protected:
        TroopIterator();
};
