#include "ConcretePot.h"

ConcretePot::ConcretePot(Product* plant): Decorator(plant) {}

ConcretePot::~ConcretePot() {}

float ConcretePot::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 60.00;
}

string ConcretePot::summary() {
    return Decorator::summary() + "Pot: Concrete Pot \n";
}

string ConcretePot::getName() {
    return Decorator::getName() + ", in a Concrete Pot";
}
