#include "Thinning.h"
#include "Plant.h"

void Thinning::prune(Plant* plant) {
    float currentHealth = plant->getHealth();
    plant->setHealth(currentHealth + 0.2f); 
    plant->setPruned(true);
}

string Thinning::print() {
    return "Thinning";
}