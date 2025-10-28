#include "SeedlingState.h"

void SeedlingState::change(Plant* plant) {
    if (plant->getHeight() >= 0.2 && plant->getHealth() >= 0.2) 
        plant->setState(new GrowingState());
}

string SeedlingState::print() {
    return "Seedling State";
}