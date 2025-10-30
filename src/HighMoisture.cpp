#include "HighMoisture.h"

void HighMoisture::water(Plant* plant) {
    plant->setWaterLevel(1); 
    plant->setTotalWater(plant->getTotalWater() + 500);
    // std::cout << "Watered high moisture plant " << plant->getName() << ". Water level set to 1 and total water increased by 500ml." << std::endl;
}

string HighMoisture::print() {
    return "High Moisture";
}