#include "DeadPruning.h"

void DeadPruning::prune(Plant* plant) {
    float currentHealth = plant->getHealth();
    plant->setHealth(currentHealth + 0.4f); 
    plant->setPruned(true);
    // std::cout << "Dead pruning performed on " << plant->getName() << ". Health increased by 0.4." << std::endl;
}

string DeadPruning::print() {
    return "Dead Pruning";
}