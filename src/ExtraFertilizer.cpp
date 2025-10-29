#include "ExtraFertilizer.h"

ExtraFertilizer::ExtraFertilizer(Product* plant): Decorator(plant) {}

ExtraFertilizer::~ExtraFertilizer() {}

float ExtraFertilizer::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 80.00;
}

string ExtraFertilizer::getSummary() {
    return Decorator::getSummary() + "Extra: Extra Fertilizer\n";
}

string ExtraFertilizer::getName() {
    string baseName = Decorator::getName();
    if (!baseName.empty() && baseName.back() == '-') {
        return baseName + " Extra Fertilizer";
    }
    return baseName + ", Extra Fertilizer";
}
