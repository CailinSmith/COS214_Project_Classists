#ifndef SPRINGFACTORY_H
#define SPRINGFACTORY_H

#include "PlantFactory.h"
class Plant; // Forward declaration

class SpringFactory : public PlantFactory {
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
