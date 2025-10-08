#ifndef AUTUMNFACTORY_H
#define AUTUMNFACTORY_H

#include "PlantFactory.h"

class Plant; // Forward declaration

class AutumnFactory : public PlantFactory {
public:
	Plant* createFlower();
	Plant* createHerb();
	Plant* createFruit();
	Plant* createVegetable();

	Plant* createSucculent();

	Plant* createAquatic();

	Plant* createIndoor();

	Plant* createMedicinal();
};

#endif
