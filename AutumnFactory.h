#ifndef AUTUMNFACTORY_H
#define AUTUMNFACTORY_H

#include "PlantFactory.h"
#include "Plant.h"
#include "Pansy.h"
#include "Thyme.h"
#include "Strawberry.h"
#include "Kale.h"
#include "Echeveria.h"
#include "Cattails.h"
#include "PeaceLily.h"
#include "Chamomile.h"

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
