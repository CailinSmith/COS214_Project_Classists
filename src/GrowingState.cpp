#include "GrowingState.h"

void GrowingState::change(Plant* plant) {
    if (plant->getHeight() >= 0.5 && plant->getHealth() >= 0.5) 
        plant->setState(new MatureState());
    else if (plant->getHealth() < 0.2) 
        plant->setState(new DyingState());
}

string GrowingState::print() {
    return "Growing";
}