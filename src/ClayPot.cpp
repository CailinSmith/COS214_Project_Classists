#include "ClayPot.h"

ClayPot::ClayPot(Product* plant): Decorator(plant) {}

ClayPot::~ClayPot() {}

float ClayPot::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 50.00;
}

string ClayPot::summary() {
    return Decorator::summary() + "Extra: Clay Pot \n";
}

string ClayPot::getName() {
    string baseName = Decorator::getName();
    if (!baseName.empty() && baseName.back() == '-') {
        return baseName + " Clay Pot";
    }
    return baseName + ", Clay Pot";
}

