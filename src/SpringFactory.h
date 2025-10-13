/**
 * @file SpringFactory.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef SPRINGFACTORY_H
#define SPRINGFACTORY_H

#include "PlantFactory.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "Lettuce.h"
#include "JadePlant.h"
#include "WaterLily.h"
#include "SnakePlant.h"
#include "AloeVera.h"

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
