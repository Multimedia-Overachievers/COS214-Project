/*
 *  Soldiers.h
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#pragma once
#include "./Troops.h"
#include "./Squad.h"
#include "./SquadIterator.h"

using namespace std;

/**
 * @brief The Soldiers class
 * @details This class is used to create the soldiers that will be used in the sim
 * This is the Composite class in the Composite Design pattern
 * This class inherits from the Troops class
 * 
 * @author Tayla Orsmond
 * @date 10/24/2022
 * 
 */
class Soldiers : public Troops
{
    public:
        Soldiers(Name name, State state);
        ~Soldiers();
        int takeDMG(int total);
        string getReport();
        vector<Troops *> disband();
        void build(vector<Troops *>& squads);
        void add(Troops * squad);
        vector<Troops *> remove(int noToRemove);
        int getTotalHP();
        int getTotalDMG();
        TroopIterator* createIterator();
        
    private:
        void changeName();
        int clearSquads();
        vector<Troops *> squads;
        int compositeBuff;
        friend class SquadIterator;
};
