#include "MediumMoisture.h"
#include "Plant.h"
#include <iostream>

void MediumMoisture::water(Plant* plant) {
    plant->setWaterLevel(1); 
    plant->setTotalWater(plant->getTotalWater() + 200);
    // std::cout << "Watered medium moisture plant " << plant->getName() << ". Water level set to 1 and total water increased by 200ml." << std::endl;
}

string MediumMoisture::print() {
    return "Medium Moisture";
}