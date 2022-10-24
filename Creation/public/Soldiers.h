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
 * This is the Concrete Product class in the Factory Design pattern
 * This class inherits from the Troops class
 * 
 * @param dmg The damage the soldiers do
 * @param hp The health of the soldiers
 * @param name The name of the soldiers (enum)
 * @param state The state of the soldiers (enum)
 * 
 * @author Tayla Orsmond
 * @date 10/19/2022
 * 
 */
class Soldiers : public Troops
{
public:
    Soldiers(Name name, State state);
    Soldiers(Name name);
    ~Soldiers();
    int takeDMG(int total);
    // void attack(Troops* enemy);
    void buffDMG(int buff);
    void buffHP(int buff);
    string getReport();
    vector<Troops *> disband();
    void build(vector<Troops *> squads);
    void add(Troops * squads);
    void remove(Troops * squads);
    int getTotalHP();
    int getTotalDMG();
    TroopIterator* createIterator();
    
private:
    void changeState();
    vector<Troops *> squads;
    int compositeBuff;
    friend class SquadIterator;
};
