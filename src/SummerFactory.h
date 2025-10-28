/**
 * @file SummerFactory.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef SUMMERFACTORY_H
#define SUMMERFACTORY_H

#include "PlantFactory.h"
#include "Chrysanthemum.h"
#include "Lavender.h"
#include "AppleTree.h"
#include "Pumpkin.h"
#include "BarrelCactus.h"
#include "WaterHyacinth.h"
#include "RubberTree.h"
#include "Coneflower.h"

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
