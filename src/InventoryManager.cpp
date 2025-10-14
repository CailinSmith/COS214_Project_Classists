#include "InventoryManager.h"

// InventoryManager* InventoryManager::getInstance() {
// 	// TODO - implement InventoryManager::getInstance
// 	throw "Not yet implemented";
// }

void InventoryManager::addToSale(Plant* plant) {
	// TODO - implement InventoryManager::addToSale
	std::cout << "Added " << plant->getName() << " to sale." << std::endl;
}

void InventoryManager::addToNursery(Plant* plant) {
	// TODO - implement InventoryManager::addToNursery
	std::cout << "Added " << plant->getName() << " to nursery." << std::endl;
}

void InventoryManager::removeFromNursery(Plant* plant) {
	// TODO - implement InventoryManager::removeFromNursery
	std::cout << "Removed " << plant->getName() << " from nursery." << std::endl;
}

void InventoryManager::removeFromSale(Plant* plant) {
	// TODO - implement InventoryManager::removeFromSale
	std::cout << "Removed " << plant->getName() << " from sale." << std::endl;
}

void InventoryManager::notifyStaff(string message) {
	// TODO - implement InventoryManager::notifyStaff
	throw "Not yet implemented";
}
