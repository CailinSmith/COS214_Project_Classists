#include "DeadState.h"

void DeadState::change(Plant* plant) {
    // Dead state does not change to any other state
}

string DeadState::print() {
    return "Dead";
}