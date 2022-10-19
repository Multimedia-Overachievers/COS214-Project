#include "Soldiers.h"

Soldiers::Soldiers(NAME name = PLATOON, STATE state) : Troops(name, state){
    switch(name){
        case PLATOON:
            setDMG(20);
            setHP(200);
            break;
        case COMPANY:
            setDMG(30);
            setHP(300);
            break;
        case BATTALION:
            setDMG(40);
            setHP(400);
            break;
        case ARMY:
            setDMG(50);
            setHP(500);
            break;
        default:
            setDMG(20);
            setHP(200);
            break;
    }
}

Soldiers::Soldiers(NAME name = PLATOON) : Troops(name){
    switch(name){
        case PLATOON:
            setDMG(20);
            setHP(200);
            break;
        case COMPANY:
            setDMG(30);
            setHP(300);
            break;
        case BATTALION:
            setDMG(40);
            setHP(400);
            break;
        case ARMY:
            setDMG(50);
            setHP(500);
            break;
        default:
            setDMG(20);
            setHP(200);
            break;
    }
}

Soldiers::~Soldiers(){
    //delete squads;
    for(int i = 0; i < squads.size(); i++){
        delete squads[i];
    }
    squads.clear();
}

int Soldiers::takeDMG(int total){
    //if my state is not defeated
    //then take the damage
    //otherwise do nothing
    if(getState() != DEFEATED || getState() != MOVING){
        int hp = getTotalHP();
        hp -= total;
        if(hp <= 0){
            setState(DEFEATED);
            setDMG(0);
            setHP(0);
            //set all my squads to defeated
            for(int i = 0; i < squads.size(); i++){
                squads[i]->takeDMG(squads[i]->getTotalHP());
            }
        }
        else{
            //else let the squads take the damage
            //start at the first squad
            //if that squad is defeated, then move to the next one
            //if all squads are defeated, then set my state to defeated
            int i = 0;
            while(total > 0){
                if(i >= squads.size()){
                    setState(DEFEATED);
                    setDMG(0);
                    setHP(0);
                    break;
                }
                else if(squads[i]->getState() != DEFEATED || squads[i]->getState() != MOVING){
                    total -= squads[i]->takeDMG(total);
                    if(squads[i]->getState() == DEFEATED){
                        i++;
                    }
                }
                else{
                    i++;
                }
            }
        }
        //clean up any squads that are defeated
        for(int i = 0; i < squads.size(); i++){
            if(squads[i]->getState() == DEFEATED){
                delete squads[i];
                squads.erase(squads.begin() + i);
            }
        }
    }
    return getTotalHP();
}

void Soldiers::buffDMG(int buff){
    //if my state is not defeated
    //then buff the damage of all my squads
    if(getState() != DEFEATED){
        for(int i = 0; i < squads.size(); i++){
            if(squads[i]->getState() != DEFEATED){
                squads[i]->buffDMG(buff);
            }
        }
        setBuffDMG(buff);
    }
}

void Soldiers::buffHP(int buff){
    //if my state is not defeated
    //then buff the hp of all my squads
    if(getState() != DEFEATED){
        for(int i = 0; i < squads.size(); i++){
            if(squads[i]->getState() != DEFEATED){
                squads[i]->buffHP(buff);
            }
        }
        setBuffHP(buff);
    }
}

string Soldiers::getReport(){
    string report = "";
    report += "Soldiers: " + to_string(getName()) + " of " + to_string(squads.size()) + " squads\n";
    report += "\tHP: " + to_string(getTotalHP()) + " ";
    report += "\tDMG: " + to_string(getTotalDMG()) + " ";
    report += "\tState: " + to_string(getState()) + " ";
    //get the report of the squads
    for(int i = 0; i < squads.size(); i++){
        report += squads[i]->getReport();
    }
    return report;
}

vector<Troops *> Soldiers::disband(){
    //disband my squads
    //clean up any defeated squads and return the vector
    vector<Troops *> disbandedSquads;
    for(int i = 0; i < squads.size(); i++){
        if(squads[i]->getState() == DEFEATED && squads[i]->getTotalHP() == 0){
            delete squads[i];
            squads.erase(squads.begin() + i);
        }
        else{
            vector<Troops *> temp = squads[i]->disband();
            for(int j = 0; j < temp.size(); j++){
                disbandedSquads.push_back(temp[j]);
            }
            temp.clear();
        }
    }
    //clear out any squads that are defeated (again, for any defeated composites but not leaves)
    for(int i = 0; i < disbandedSquads.size(); i++){
        if(disbandedSquads[i]->getState() == DEFEATED){
            delete disbandedSquads[i];
            disbandedSquads.erase(squads.begin() + i);
        }
    }
    if(disbandedSquads.size() == 0){
        return vector<Troops *>();
    }
    return disbandedSquads;
}

void Soldiers::build(vector<Troops *> squads){
    //build my squads
    //if my state is not defeated
    //add the squads to my vector
    if(getState() != DEFEATED){
        for(int i = 0; i < squads.size(); i++){
            this->squads.push_back(squads[i]);
        }
        squads.clear();
    }
    //depending on the number of squads, set my name and my compositeBuff
    changeState();
}

void Soldiers::add(Troops * squad){
    //if my state is not defeated
    //then add the squad to my vector
    if(getState() != DEFEATED){
        squads.push_back(squad);
    }
    //depending on the number of squads, set my name and my compositeBuff
    changeState();
}

void Soldiers::remove(Troops * squad){
    //if my state is not defeated
    //then remove the squad from my vector
    if(getState() != DEFEATED){
        for(int i = 0; i < squads.size(); i++){
            if(squads[i] == squad){
                squads.erase(squads.begin() + i);
                break;
            }
        }
    }
    //depending on the number of squads, set my name and my compositeBuff
    changeState();
}

int Soldiers::getTotalHP(){
    //if my state is not defeated
    //then return the total hp of all my squads
    if(getState() != DEFEATED){
        int total = getHP();
        for(int i = 0; i < squads.size(); i++){
            total += squads[i]->getTotalHP();
        }
        return total;
    }
    return 0;
}

int Soldiers::getTotalDMG(){
    //if my state is not defeated
    //then return the total damage of all my squads
    if(getState() != DEFEATED){
        int total = getDMG();
        for(int i = 0; i < squads.size(); i++){
            total += squads[i]->getTotalDMG();
        }
        return total;
    }
    return 0;
}

void Soldiers::changeState(){
    //change my state depending on the number of squads
    if(squads.size() < 2){
        setName(PLATOON);
        this->compositeBuff = 10;
    }
    else if(squads.size() < 6 && squads.size() > 2){
        setName(COMPANY);
        this->compositeBuff = 20;
    }
    else if(squads.size() < 24 && squads.size() > 6){
        setName(BATTALION);
        this->compositeBuff = 30;
    }
    else{
        setName(ARMY);
        this->compositeBuff = 40;
    }  
}

TroopIterator * Soldiers::createIterator(){
    return new SquadIterator(this);
}