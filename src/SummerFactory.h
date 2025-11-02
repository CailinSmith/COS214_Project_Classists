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

/**
 * @class SummerFactory
 * @author Cailin Smith
 * @brief Concrete factory for creating summer-season plants.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteFactory
 * 
 * This class implements the PlantFactory interface to create plants that
 * are appropriate for the summer season. Each creation method returns a
 * specific summer plant variety (Chrysanthemum, Lavender, Apple Tree,
 * Pumpkin, Barrel Cactus, Water Hyacinth, Rubber Tree, Coneflower).
 * 
 * @see PlantFactory
 * @see Chrysanthemum
 * @see Lavender
 * @see AppleTree
 * @see Pumpkin
 * @see BarrelCactus
 * @see WaterHyacinth
 * @see RubberTree
 * @see Coneflower
 */
class SummerFactory : public PlantFactory {

public:
	/**
	 * @brief Creates a summer flower.
	 * @return Plant* Pointer to a newly created Chrysanthemum.
	 */
	Plant* createFlower();

	/**
	 * @brief Creates a summer herb.
	 * @return Plant* Pointer to a newly created Lavender plant.
	 */
	Plant* createHerb();

	/**
	 * @brief Creates a summer fruit.
	 * @return Plant* Pointer to a newly created Apple Tree.
	 */
	Plant* createFruit();

	/**
	 * @brief Creates a summer vegetable.
	 * @return Plant* Pointer to a newly created Pumpkin plant.
	 */
	Plant* createVegetable();

	/**
	 * @brief Creates a summer succulent.
	 * @return Plant* Pointer to a newly created Barrel Cactus.
	 */
	Plant* createSucculent();

	/**
	 * @brief Creates a summer aquatic plant.
	 * @return Plant* Pointer to a newly created Water Hyacinth.
	 */
	Plant* createAquatic();

	/**
	 * @brief Creates a summer indoor plant.
	 * @return Plant* Pointer to a newly created Rubber Tree.
	 */
	Plant* createIndoor();

	/**
	 * @brief Creates a summer medicinal plant.
	 * @return Plant* Pointer to a newly created Coneflower.
	 */
	Plant* createMedicinal();
};

#endif
