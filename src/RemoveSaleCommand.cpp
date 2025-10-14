#include "RemoveSaleCommand.h"

RemoveSaleCommand::RemoveSaleCommand(Plant* plant, InventoryManager* im) : StaffCommand(plant, im, nullptr) {}

void RemoveSaleCommand::execute() {
	inventoryManager->removeFromSale(plant);
}
