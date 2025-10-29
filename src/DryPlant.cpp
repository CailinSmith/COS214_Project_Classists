#include "DryPlant.h"

void DryPlant::water(Plant* plant) {
    plant->setWaterLevel(1);
    plant->setTotalWater(plant->getTotalWater() + 75);
    // std::cout << "Watered dry plant " << plant->getName() << ". Water level set to 1 and total water increased by 75ml." << std::endl;
}

string DryPlant::print() {
    return "Dry Plant";
}