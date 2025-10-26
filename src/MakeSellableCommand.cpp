#include "MakeSellableCommand.h"

MakeSellableCommand::MakeSellableCommand(Plant* plant, InventoryManager* im) : StaffCommand() {
	this->plant = plant;
	this->inventoryManager = im;
}

void MakeSellableCommand::execute() {
	if (inventoryManager != nullptr && plant != nullptr) {
		inventoryManager->removeFromNursery(plant);
		inventoryManager->addToSale(plant);
	}
}
