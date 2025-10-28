#include "SeedState.h"

void SeedState::change(Plant* plant) {
    if (plant->getHeight() >= 0.1 && plant->getHealth() > 0.1) 
        plant->setState(new SeedlingState());
}

string SeedState::print() {
    return "Seed State";
}