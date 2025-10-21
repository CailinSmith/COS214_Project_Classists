#include "Nursery.h"
#include "Spring.h"
#include "SpringFactory.h"
#include <iostream>

Nursery::Nursery(InventoryManager* manager) : inventoryManager(manager) {
	currentSeason = new Spring();
	currentFactory = new SpringFactory();
}

Nursery::~Nursery() {
	delete currentSeason;
	delete currentFactory;
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