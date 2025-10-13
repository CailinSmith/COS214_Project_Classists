/**
 * @file PlantFactory.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"
class PlantFactory {


public:
	virtual Plant* createFlower() = 0;

	virtual Plant* createHerb() = 0;

	virtual Plant* createFruit() = 0;

	virtual Plant* createVegetable() = 0;

	virtual Plant* createSucculent() = 0;

	virtual Plant* createAquatic() = 0;

	virtual Plant* createIndoor() = 0;

	virtual Plant* createMedicinal() = 0;
};

#endif
