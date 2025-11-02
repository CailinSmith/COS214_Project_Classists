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

/**
 * @class AutumnFactory
 * @author Cailin Smith
 * @brief Factory for creating autumn-season plants.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteFactory
 * 
 * This class implements the PlantFactory interface to create specific plant types
 * that are available during the Autumn season. It provides factory methods for creating
 * flowers, herbs, fruits, vegetables, succulents, aquatic plants, indoor plants,
 * and medicinal plants suitable for autumn.
 * 
 * @see PlantFactory
 * @see Plant
 */
class AutumnFactory : public PlantFactory {
public:
	/**
	 * @brief Creates an autumn flower plant.
	 * @return Plant* Pointer to a newly created autumn flower (Pansy).
	 */
	Plant* createFlower();
	
	/**
	 * @brief Creates an autumn herb plant.
	 * @return Plant* Pointer to a newly created autumn herb (Thyme).
	 */
	Plant* createHerb();
	
	/**
	 * @brief Creates an autumn fruit plant.
	 * @return Plant* Pointer to a newly created autumn fruit (Strawberry).
	 */
	Plant* createFruit();
	
	/**
	 * @brief Creates an autumn vegetable plant.
	 * @return Plant* Pointer to a newly created autumn vegetable (Kale).
	 */
	Plant* createVegetable();

	/**
	 * @brief Creates an autumn succulent plant.
	 * @return Plant* Pointer to a newly created autumn succulent (Echeveria).
	 */
	Plant* createSucculent();

	/**
	 * @brief Creates an autumn aquatic plant.
	 * @return Plant* Pointer to a newly created autumn aquatic plant (Cattails).
	 */
	Plant* createAquatic();

	/**
	 * @brief Creates an autumn indoor plant.
	 * @return Plant* Pointer to a newly created autumn indoor plant (PeaceLily).
	 */
	Plant* createIndoor();

	/**
	 * @brief Creates an autumn medicinal plant.
	 * @return Plant* Pointer to a newly created autumn medicinal plant (Chamomile).
	 */
	Plant* createMedicinal();
};

#endif
