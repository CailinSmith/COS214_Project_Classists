#include "Nursery.h"

void Nursery::setSeason(SeasonState* season) {
	// TODO - implement Nursery::setSeason
	throw "Not yet implemented";
}

string Nursery::getSeason() {
	// TODO - implement Nursery::getSeason
	throw "Not yet implemented";
}

void Nursery::setFactory(PlantFactory* factory) {
	// TODO - implement Nursery::setFactory
	throw "Not yet implemented";
}

void Nursery::changeSeason() {
	// TODO - implement Nursery::changeSeason
	throw "Not yet implemented";
}

void Nursery::stockNursery() {
	if (!currentFactory) {
		std::cout << "currentFactory is null" << std::endl;
		return;
	}
	inventoryManager->addToNursery(currentFactory->createFlower());
	inventoryManager->addToNursery(currentFactory->createHerb());
	inventoryManager->addToNursery(currentFactory->createVegetable());
	inventoryManager->addToNursery(currentFactory->createFruit());
	inventoryManager->addToNursery(currentFactory->createSucculent());
	inventoryManager->addToNursery(currentFactory->createAquatic());
	inventoryManager->addToNursery(currentFactory->createIndoor());
	inventoryManager->addToNursery(currentFactory->createMedicinal());
}
