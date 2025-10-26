#include "RemoveSaleCommand.h"

RemoveSaleCommand::RemoveSaleCommand(Plant* plant, InventoryManager* im) : StaffCommand() {
	this->plant = plant;
	this->inventoryManager = im;
}

void RemoveSaleCommand::execute() {
	inventoryManager->removeFromSale(plant);
}
