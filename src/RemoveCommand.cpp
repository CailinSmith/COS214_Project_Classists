#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(Plant* plant, InventoryManager* im) : StaffCommand(plant, im, nullptr) {}

void RemoveCommand::execute() {
	inventoryManager->removeFromNursery(plant);
}
