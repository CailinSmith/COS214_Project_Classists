#include "MakeSellableCommand.h"

MakeSellableCommand::MakeSellableCommand(Plant* plant, InventoryManager* im) 
		: StaffCommand(plant, im, nullptr) {}

void MakeSellableCommand::execute() {
	inventoryManager->removeFromNursery(plant);
	inventoryManager->addToSale(plant);
}
