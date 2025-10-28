#include "WinterFactory.h"

Plant* WinterFactory::createFlower() {
	return new Sunflower();
}

Plant* WinterFactory::createHerb() {
	return new Rosemary();
}

Plant* WinterFactory::createFruit() {
	return new OrangeTree();
}

Plant* WinterFactory::createVegetable() {
	return new Cucumber();
}

Plant* WinterFactory::createSucculent() {
	return new ChristmasCactus();
}

Plant* WinterFactory::createAquatic() {
	return new WaterLettuce();
}

Plant* WinterFactory::createIndoor() {
	return new Pothos();
}

Plant* WinterFactory::createMedicinal() {
	return new Ginger();
}
