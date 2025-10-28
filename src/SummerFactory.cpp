#include "SummerFactory.h"

Plant* SummerFactory::createFlower() {
	return new Chrysanthemum();
}

Plant* SummerFactory::createHerb() {
	return new Lavender();
}

Plant* SummerFactory::createFruit() {
	return new AppleTree();
}

Plant* SummerFactory::createVegetable() {
	return new Pumpkin();
}

Plant* SummerFactory::createSucculent() {
	return new BarrelCactus();
}

Plant* SummerFactory::createAquatic() {
	return new WaterHyacinth();
}

Plant* SummerFactory::createIndoor() {
	return new RubberTree();
}

Plant* SummerFactory::createMedicinal() {
	return new Coneflower();
}
