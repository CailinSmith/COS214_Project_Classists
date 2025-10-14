#include "SellCommand.h"

SellCommand::SellCommand(Plant* plant, InventoryManager* im) : StaffCommand(plant, im, nullptr) {}

void SellCommand::execute() {
	inventoryManager->removeFromSale(plant);
	plant->setSold(true);
}
