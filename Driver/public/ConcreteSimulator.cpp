#include "ConcreteSimulator.h"

void ConcreteSimulator::action(FactionAction* myAction) {
    myAction->execute();
}
