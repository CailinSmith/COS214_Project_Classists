#include "ExtraFertilizer.h"

ExtraFertilizer::ExtraFertilizer(Product* plant): Decorator(plant) {}

ExtraFertilizer::~ExtraFertilizer() {}

float ExtraFertilizer::calculateCost(string currentSeason) {
    return Decorator::calculateCost(currentSeason) + 80.00;
}

string ExtraFertilizer::summary() {
    return Decorator::summary() + "Additional resources: Extra Fertilizer\n";
}

string ExtraFertilizer::getName() {
    return Decorator::getName() + ", with extra fertilizer";
}
