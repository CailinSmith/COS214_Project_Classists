#include "DeadState.h"

void DeadState::change(Plant* plant) {
    (void)plant;
}

string DeadState::print() {
    return "Dead";
}