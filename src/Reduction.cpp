#include "Reduction.h"
#include "Plant.h"

void Reduction::prune(Plant* plant) {
    float currentHeight = plant->getHeight();
    plant->setHeight(currentHeight * 0.8f); 
    plant->setPruned(true);
}

string Reduction::print() {
    return "Reduction";
}
