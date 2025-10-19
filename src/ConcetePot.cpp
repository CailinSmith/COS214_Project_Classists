#include "ConcetePot.h"

ConcretePot::ConcretePot(Product* plant): Decorator(plant) {}

ConcretePot::~ConcretePot() {}

float ConcretePot::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 60.00;
}

string ConcretePot::getSummary() {
    return Decorator::getSummary() + "Pot: Concrete Pot \n";
}

string ConcretePot::getName() {
    return Decorator::getName() + ", in a Concrete Pot";
}
