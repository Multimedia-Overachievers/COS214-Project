/*
 *  Squad.h
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#pragma once
#include "./Troops.h"
#include "./SquadIterator.h"

using namespace std;
/**
 * @brief The Squad class
 * @details This class is used to create the squads that will be used in the sim
 * This is the Leaf class in the Composite Design pattern
 * This class inherits from the Troops class
 * 
 * @author Tayla Orsmond
 * @date 11/05/2022
 * 
 */
class Squad : public Troops 
{
    public:
        Squad(Name name = SquadStd, State state = Ready);
        ~Squad();
        int takeDMG(int total);
        string getReport();
        vector<Troops *> disband();
        vector<Troops *> disband(int noToRemove);
        void build(vector<Troops *> squads);
        void build(Troops * squad);
        void build(int noToAdd);
        int getTotalHP();
        int getTotalDMG();
        int getTotalTroops();
    private:
        TroopIterator * createIterator();
        vector<Troops *> getTroops();
};
