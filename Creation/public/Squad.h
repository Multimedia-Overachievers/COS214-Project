//Tayla Orsmond u21467456
#include "Troops.h"

using namespace std;
/**
 * @brief The Squad class
 * @details This class is used to create the squads that will be used in the sim
 * This is the Leaf class in the Composite Design pattern
 * This is the Concrete Product class in the Factory Design pattern
 * This class inherits from the Troops class
 * 
 * @param dmg The damage the squads do
 * @param hp The health of the squads
 * @param name The name of the squads (enum)
 * @param state The state of the squads (enum)
 * 
 * @author Tayla Orsmond
 * @date 10/19/2022
 * 
 */
class Squad : public Troops{
    public:
        Squad(NAME name, STATE state);
        Squad(NAME name);
        ~Squad();
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
};
