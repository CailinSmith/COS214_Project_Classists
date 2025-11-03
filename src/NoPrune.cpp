#include "NoPrune.h"
#include "Plant.h"

void NoPrune::prune(Plant* plant) {
    plant->setPruned(true);
    // std::cout << "No pruning performed on " << plant->getName() << "." << std::endl;
}

string NoPrune::print() {
    return "No Prune";
}
