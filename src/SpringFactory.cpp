#include "SpringFactory.h"

Plant* SpringFactory::createFlower() {
	return new Rose();
}

Plant* SpringFactory::createHerb() {
	return new Basil();
}

Plant* SpringFactory::createFruit() {
	return new Tomato();
}

Plant* SpringFactory::createVegetable() {
	return new Lettuce();
}

Plant* SpringFactory::createSucculent() {
	return new JadePlant();
}

Plant* SpringFactory::createAquatic() {
	return new WaterLily();
}

Plant* SpringFactory::createIndoor() {
	return new SnakePlant();
}

Plant* SpringFactory::createMedicinal() {
	return new AloeVera();
}
