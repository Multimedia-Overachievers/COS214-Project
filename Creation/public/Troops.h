/*
 *  Troops.h
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#pragma once
#include <vector>
#include <string>
#include "../../Driver/public/enums.h"

using namespace std;
/**
 * @brief The Troops class
 * @details This class is used to create the troops that will be used in the sim
 * This is the Component class in the Composite Design pattern
 * This is an abstract class
 * 
 * @author Tayla Orsmond
 * @date 10/24/2022
 * 
 */

class Troops 
{
    public:
        Troops(NAME name, STATE state);
        virtual ~Troops();
        virtual int takeDMG(int total) = 0;
        virtual string getReport() = 0;
        virtual vector<Troops *> disband() = 0;
        virtual void build(vector<Troops *> squads) = 0;
        virtual void add(Troops * squad) = 0;
        virtual vector<Troops *> remove(int noToRemove) = 0;
        virtual int getTotalHP() = 0;
        virtual int getTotalDMG() = 0;
        enum STATE getState(){return this->state;}
        enum NAME getName(){return this->name;}

    protected:
        void setState(STATE state){this->state = state;}
        void setName(NAME name){this->name = name;}
        void setHP(int hp){this->hp = hp;}
        void setDMG(int dmg){this->dmg = dmg;}
        int getHP(){return this->hp;}
        int getDMG(){return this->dmg;}

    private:
        int dmg;
        int hp;
        STATE state;
        NAME name;
};