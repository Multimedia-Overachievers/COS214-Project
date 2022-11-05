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
 * @date 11/05/2022
 * 
 */

class Troops 
{
    friend class MoveTroops;
    public:
        Troops(Name name, State state);
        virtual ~Troops();
        virtual int takeDMG(int total) = 0;
        virtual string getReport() = 0;
        virtual vector<Troops *> disband() = 0;
        virtual void build(vector<Troops *> squads) = 0;
        virtual void add(Troops * squad) = 0;
        virtual vector<Troops *> remove(int noToRemove) = 0;
        virtual int getTotalHP() = 0;
        virtual int getTotalDMG() = 0;
        // virtual TroopIterator* createIterator() = 0;
        // virtual int getTotalTroops() = 0;
        enum State getState(){return this->state;}
        enum Name getName(){return this->name;}
        void changeState(){
            if(this->state == State::Moving){
                this->state = State::Ready;
            }
            else if(this->state == State::Ready){
                this->state = State::Moving;
            }
        };

    protected:
        void setState(State state){this->state = state;}
        void setName(Name name){this->name = name;}
        void setHP(int hp){this->hp = hp;}
        void setDMG(int dmg){this->dmg = dmg;}
        int getHP(){return this->hp;}
        int getDMG(){return this->dmg;}

    private:
        int dmg;
        int hp;
        State state;
        Name name;
};