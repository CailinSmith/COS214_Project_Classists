#include "ClayPot.h"

ClayPot::ClayPot(Product* plant): Decorator(plant) {}

ClayPot::~ClayPot() {}

float ClayPot::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 50.00;
}

string ClayPot::summary() {
    return Decorator::summary() + "Pot: Clay Pot \n";
}

string ClayPot::getName() {
    return Decorator::getName() + ", in a Clay Pot";
}

