#ifndef SUMMERFACTORY_H
#define SUMMERFACTORY_H

#include "PlantFactory.h"

class SummerFactory : public PlantFactory {

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
