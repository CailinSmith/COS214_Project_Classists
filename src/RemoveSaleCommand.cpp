#include "RemoveSaleCommand.h"

RemoveSaleCommand::RemoveSaleCommand(Plant* plant, InventoryManager* im) : StaffCommand() {
	this->plant = plant;
	this->inventoryManager = im;
}

void RemoveSaleCommand::execute() {
	if (inventoryManager != nullptr && plant != nullptr)
		inventoryManager->removeFromSale(plant);
}
