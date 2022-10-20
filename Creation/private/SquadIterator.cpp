#include "../public/SquadIterator.h"

SquadIterator::SquadIterator(){
    it = vector<Troops *>::iterator();
    mySoldiers = nullptr;
}

SquadIterator::SquadIterator(Soldiers * soldiers){
    it = soldiers->squads.begin();
    mySoldiers = soldiers;
}

SquadIterator::~SquadIterator(){
    it = vector<Troops *>::iterator();
    mySoldiers = nullptr;
}

Troops * SquadIterator::first(){
    it = mySoldiers->squads.begin();
    return *it;
}

Troops * SquadIterator::next(){
    it++;
    return *it;
}

bool SquadIterator::isDone(){
    return it == mySoldiers->squads.end();
}

Troops * SquadIterator::current(){
    return *it;
}

vector<Troops *>::iterator SquadIterator::at(){
    return it;
}

