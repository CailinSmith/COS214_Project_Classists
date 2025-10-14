#include "MatureState.h"

void MatureState::change(Plant* plant) {
    if (plant->getHeight() >= 0.9 && plant->getHealth() >= 0.9)
        plant->setState(new ReadyForSaleState());
    else if (plant->getHealth() < 0.5)
        plant->setState(new DyingState());
}

string MatureState::print() {
    return "Mature";
}