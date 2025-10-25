#include "StaffCheckStockCommand.h"
#include <iostream>

StaffCheckStockCommand::StaffCheckStockCommand(Plant* p, InventoryManager* im) 
    : StaffCommand(p, im, nullptr) {
}

StaffCheckStockCommand::~StaffCheckStockCommand() {}

void StaffCheckStockCommand::execute() {
    if (plant && inventoryManager) {
        stock = 0;
        std::string targetName = plant->getName();

        const auto& salePlants = inventoryManager->getForSalePlants();
        for (Plant* salePlant : salePlants) {
            if (salePlant && salePlant->getName() == targetName) {
                stock++;
            }
        }
        
        // std::cout << "Stock count for " << plant->getName() << ": " << stock << std::endl;
    } else {
        std::cout << "Error: Invalid plant or inventory manager" << std::endl;
        stock = 0;
    }
}

int StaffCheckStockCommand::getStock() {
    return stock;
}