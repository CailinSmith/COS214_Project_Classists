#ifndef WINTERFACTORY_H
#define WINTERFACTORY_H

#include "PlantFactory.h"

class WinterFactory : public PlantFactory {

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
