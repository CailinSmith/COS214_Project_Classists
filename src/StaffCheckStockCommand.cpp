#include "StaffCheckStockCommand.h"
#include "Nursery.h"
#include <iostream>

StaffCheckStockCommand::StaffCheckStockCommand(Plant* p, InventoryManager* im) : StaffCommand() {
    plant = p;
    (void) im;
    // don't store the passed InventoryManager pointer; we'll fetch the current manager
    // from the Nursery singleton at execution time to avoid iterating a freed manager.
}

StaffCheckStockCommand::~StaffCheckStockCommand() {}

void StaffCheckStockCommand::execute() {
    InventoryManager* inventoryManager = nullptr;
    Nursery* nursery = Nursery::getInstance();
    if (nursery) {
        inventoryManager = nursery->getInventoryManager();
    }

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