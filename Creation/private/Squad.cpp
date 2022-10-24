/*
 *  Squad.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/Squad.h"

Squad::Squad(NAME name = SQUAD, STATE state = READY) : Troops(name, state){
    setDMG(SquadDmg);
    setHP(SquadHp);
}

Squad::Squad(NAME name = SQUAD) : Troops(name){
    setDMG(SquadDmg);
    setHP(SquadHp);
}

Squad::~Squad(){
}

int Squad::takeDMG(int total){
    int hp = getTotalHP();
    hp -= total;
    setHP(hp);
    if(hp <= 0){
        setState(DEFEATED);
        setDMG(0);
        setHP(0);
    }
    return hp;
}

void Squad::buffDMG(int buff){
    setBuffDMG(buff);
}

void Squad::buffHP(int buff){
    setBuffHP(buff);
}

string Squad::getReport(){
    string report = "";
    report += "SQUAD: \n";
    report += "\tHP: " + to_string(getTotalHP()) + " ";
    report += "\tDMG: " + to_string(getTotalDMG()) + " ";
    report += "\tState: " + to_string(getState()) + "\n";
    return report;
}

vector<Troops *> Squad::disband(){
    vector<Troops *> squads;
    squads.push_back(this);
    return squads;
}

void Squad::build(vector<Troops *> squads){
    //do nothing
    for(int i = 0; i < squads.size(); i++){
        delete squads[i];
    }
    squads.clear();
}

void Squad::add(Troops * squad){
    //recycle me if my state is DEFATED
    //otherwise do nothing
    if(getState() == DEFEATED){
        setHP(squad->getTotalHP());
        setDMG(squad->getTotalDMG());
        setState(READY);
    }
    delete squad;
    squad = nullptr;
}

void Squad::remove(Troops * squad){
    //do nothing
    delete squad;
    squad = nullptr;
}

int Squad::getTotalHP(){
    return getHP();
}

int Squad::getTotalDMG(){
    return getDMG();
}

