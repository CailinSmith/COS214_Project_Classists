#include "ReadyForSaleState.h"

void ReadyForSaleState::change(Plant* plant) {
    if (plant->getHealth() <= 0.7)
        plant->setState(new MatureState());
}

string ReadyForSaleState::print() {
    return "Ready for Sale";
}