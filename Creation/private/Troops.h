//Tayla Orsmond u21467456
#pragma once
#include <vector>
#include <string>

using namespace std;
/**
 * @brief The Troops class
 * @details This class is used to create the troops that will be used in the sim
 * This is the Component class in the Composite Design pattern
 * This is the Product class in the Factory Design pattern
 * This is an abstract class
 *
 * @param dmg The damage the troops do
 * @param hp The health of the troops
 * @param name The name of the troops (enum)
 * @param state The state of the troops (enum)
 * 
 * @author Tayla Orsmond
 * @date 10/19/2022
 * 
 */

class Troops{
    protected:
    enum STATE {MOVING, READY, DEFEATED};
    enum NAME {SQUAD, PLATOON, COMPANY, BATTALION, ARMY};
    public:
        Troops(NAME name, STATE state);
        Troops(NAME name);
        virtual ~Troops();
        virtual int takeDMG(int total) = 0;
        // virtual void attack(Troops* enemy) = 0;
        virtual void buffDMG(int buff) = 0;
        virtual void buffHP(int buff) = 0;
        virtual string getReport() = 0;
        virtual vector<Troops *> disband() = 0;
        virtual void build(vector<Troops *> squads) = 0;
        virtual void add(Troops * squads) = 0;
        virtual void remove(Troops * squads) = 0;
        virtual int getTotalHP() = 0;
        virtual int getTotalDMG() = 0;
        enum STATE getState(){return this->state;}
        enum NAME getName(){return this->name;}
    protected:
        void setState(STATE state){this->state = state;}
        void setName(NAME name){this->name = name;}
        void setHP(int hp){this->hp = hp;}
        void setDMG(int dmg){this->dmg = dmg;}
        void setBuffDMG(int buff){this->buffDmg = buff;}
        void setBuffHP(int buff){this->buffHp = buff;}
        int getHP(){return this->hp;}
        int getDMG(){return this->dmg;}
    private:
        int dmg;
        int hp;
        int buffDmg;
        int buffHp;
        STATE state;
        NAME name;
};