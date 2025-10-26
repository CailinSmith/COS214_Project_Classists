#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(Plant* plant, InventoryManager* im) : StaffCommand() {
	this->plant = plant;
	this->inventoryManager = im;
}

void RemoveCommand::execute() {
	inventoryManager->removeFromNursery(plant);
}
