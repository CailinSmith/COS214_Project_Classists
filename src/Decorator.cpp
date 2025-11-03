#include "Decorator.h"

Decorator::Decorator(Product* plant){
    this->plant=plant;
}

Decorator::~Decorator() {
    delete plant;
}

float Decorator::calculateCost(string currentSeason) {
    return plant->calculateCost(currentSeason);
}

string Decorator::summary() {
    return plant->summary();
}

string Decorator::getName() {
    Plant* directCast = dynamic_cast<Plant*>(plant);
    if (directCast != nullptr) 
        return directCast->getName()+" -";  
    return plant->getName();
}

Product* Decorator::removeDecorator() {
    Product* innerProduct = this->plant;
    this->plant = nullptr;  // Prevent deletion in destructor
    return innerProduct;
}

Plant *Decorator::getBasePlant() {
    if (plant == nullptr) {
        return nullptr;
    }
    
    Plant* directCast = dynamic_cast<Plant*>(plant);
    if (directCast != nullptr) {
        return directCast;  
    }
    
    return plant->getBasePlant();
}
