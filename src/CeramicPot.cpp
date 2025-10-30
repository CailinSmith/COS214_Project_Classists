#include "CeramicPot.h"

CeramicPot::CeramicPot(Product* plant): Decorator(plant) {}

CeramicPot::~CeramicPot() {}

float CeramicPot::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 80.00;
}

string CeramicPot::summary() {
    return Decorator::summary() + "Pot: Ceramic Pot \n";
}

string CeramicPot::getName() {
    return Decorator::getName() + ", in a Ceramic Pot";
}
