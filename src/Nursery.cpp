#include "Nursery.h"
#include "Spring.h"
#include "SpringFactory.h"
#include <iostream>

Nursery* Nursery::instance = nullptr;

Nursery::Nursery(InventoryManager* manager) : inventoryManager(manager) {
	currentSeason = new Spring();
	currentFactory = new SpringFactory();
}

Nursery* Nursery::getInstance(InventoryManager* manager) {
	if (instance == nullptr) {
		if (manager == nullptr) {
			std::cout << "Error: InventoryManager is required for first initialization of Nursery" << std::endl;
			return nullptr;
		}
		instance = new Nursery(manager);
	}
	return instance;
}

void Nursery::destroyInstance() {
	if (instance != nullptr) {
		delete instance;
		// Nursery::~Nursery sets instance = nullptr but clear again for safety
		instance = nullptr;
	}
}

Nursery::~Nursery() {
	delete currentSeason;
	delete currentFactory;
	instance = nullptr;
}

//clear the stored InventoryManager pointer (used when the manager is destroyed)
void Nursery::clearInventoryManager() {
	inventoryManager = nullptr;
}

InventoryManager* Nursery::getInventoryManager() {
	return inventoryManager;
}

void Nursery::setSeason(SeasonState* season) {
	if (currentSeason) 
		delete currentSeason;
	currentSeason = season;
}

string Nursery::getSeason() {
	if (currentSeason) 
		return currentSeason->print();
	return "No season set";
}

void Nursery::setFactory(PlantFactory* factory) {
	if (currentFactory) 
		delete currentFactory;
	currentFactory = factory;
}

void Nursery::changeSeason() {
	if (currentSeason) 
		currentSeason->change(this);
}

void Nursery::stockNursery() {
	if (!currentFactory) {
		std::cout << "currentFactory is null" << std::endl;
		return;
	}
	// inventoryManager->addToNursery(currentFactory->createFlower());
	// inventoryManager->addToNursery(currentFactory->createHerb());
	// inventoryManager->addToNursery(currentFactory->createVegetable());
	// inventoryManager->addToNursery(currentFactory->createFruit());
	// inventoryManager->addToNursery(currentFactory->createSucculent());
	// inventoryManager->addToNursery(currentFactory->createAquatic());
	// inventoryManager->addToNursery(currentFactory->createIndoor());
	// inventoryManager->addToNursery(currentFactory->createMedicinal());
}