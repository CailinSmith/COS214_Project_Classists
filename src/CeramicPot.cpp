#include "CeramicPot.h"

CeramicPot::CeramicPot(Product* plant): Decorator(plant) {}

CeramicPot::~CeramicPot() {}

float CeramicPot::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 80.00;
}

string CeramicPot::summary() {
    return Decorator::summary() + "Extra: Ceramic Pot \n";
}

string CeramicPot::getName() {
    string baseName = Decorator::getName();
    if (!baseName.empty() && baseName.back() == '-') {
        return baseName + " Ceramic Pot";
    }
    return baseName + ", Ceramic Pot";
}
