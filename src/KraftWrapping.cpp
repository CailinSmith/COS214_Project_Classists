#include "KraftWrapping.h"

KraftWrapping::KraftWrapping(Product* plant): Decorator(plant) {}

KraftWrapping::~KraftWrapping() {}

float KraftWrapping::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 20.00;
}

string KraftWrapping::summary() {
    return Decorator::summary() + "Extra: Kraft Wrapping\n";

}

string KraftWrapping::getName() {
    string baseName = Decorator::getName();
    if (!baseName.empty() && baseName.back() == '-') {
        return baseName + " Kraft Wrapping";
    }
    return baseName + ", Kraft Wrapping";
}
