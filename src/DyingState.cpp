#include "DyingState.h"

void DyingState::change(Plant* plant) {
    if (plant->getHealth() == 0) 
        plant->setState(new DeadState());
    else if (plant->getHeight() >= 0.5 && plant->getHealth() >= 0.5)
        plant->setState(new MatureState());
    else if (plant->getHeight() >= 0.2 && plant->getHealth() >= 0.2) 
        plant->setState(new GrowingState());
    plant->setPruned(false);
}

string DyingState::print() {
    return "Dying";
}