/**
 * @file WinterFactory.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef WINTERFACTORY_H
#define WINTERFACTORY_H

#include "PlantFactory.h"
#include "Sunflower.h"
#include "Rosemary.h"
#include "OrangeTree.h"
#include "Cucumber.h"
#include "ChristmasCactus.h"
#include "WaterLettuce.h"
#include "Pothos.h"
#include "Ginger.h"

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
