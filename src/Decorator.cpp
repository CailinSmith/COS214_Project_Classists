#include "Decorator.h"

Decorator::Decorator(Product* plant){
    this->plant=plant;
}

Decorator::~Decorator() {
    if (plant != nullptr) {
        delete plant;
    }
}

float Decorator::calculateCost(string currentSeason) {
    return plant->calculateCost(currentSeason);
}

string Decorator::getSummary() {
    return plant->getSummary();
}

string Decorator::getName() {
    return plant->getName();
}

Product* Decorator::removeDecorator() {
    Product* innerProduct = this->plant;
    this->plant = nullptr;  // Prevent deletion in destructor
    return innerProduct;
}
