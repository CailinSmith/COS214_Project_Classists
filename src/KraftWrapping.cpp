#include "KraftWrapping.h"

KraftWrapping::KraftWrapping(Product* plant): Decorator(plant) {}

KraftWrapping::~KraftWrapping() {}

float KraftWrapping::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 20.00;
}

string KraftWrapping::getSummary() {
    return Decorator::getSummary() + "Additional resources: Kraft Wrapping\n";
}

string KraftWrapping::getName() {
    return Decorator::getName() + " with kraft wrapping";
}
