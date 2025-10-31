#include "ConcretePot.h"

ConcretePot::ConcretePot(Product* plant): Decorator(plant) {}

ConcretePot::~ConcretePot() {}

float ConcretePot::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 60.00;
}

string ConcretePot::summary() {
    return Decorator::summary() + "Extra: Concrete Pot \n";
}

string ConcretePot::getName() {
    string baseName = Decorator::getName();
    if (!baseName.empty() && baseName.back() == '-') {
        return baseName + " Concrete Pot";
    }
    return baseName + ", Concrete Pot";
}
