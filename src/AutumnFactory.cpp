#include "AutumnFactory.h"

Plant* AutumnFactory::createFlower() {
	return new Pansy();
}

Plant* AutumnFactory::createHerb() {
	return new Thyme();
}

Plant* AutumnFactory::createFruit() {
	return new Strawberry();
}

Plant* AutumnFactory::createVegetable() {
	return new Kale();
}

Plant* AutumnFactory::createSucculent() {
	return new Echeveria();
}

Plant* AutumnFactory::createAquatic() {
	return new Cattails();
}

Plant* AutumnFactory::createIndoor() {
	return new PeaceLily();
}

Plant* AutumnFactory::createMedicinal() {
	return new Chamomile();
}
