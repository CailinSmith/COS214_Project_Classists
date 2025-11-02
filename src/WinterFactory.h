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

/**
 * @class WinterFactory
 * @author Cailin Smith
 * @brief Concrete factory for creating winter-season plants.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteFactory
 * 
 * This class implements the PlantFactory interface to create plants that
 * are appropriate for the winter season. Each creation method returns a
 * specific winter plant variety (Sunflower, Rosemary, Orange Tree,
 * Cucumber, Christmas Cactus, Water Lettuce, Pothos, Ginger).
 * 
 * @see PlantFactory
 * @see Sunflower
 * @see Rosemary
 * @see OrangeTree
 * @see Cucumber
 * @see ChristmasCactus
 * @see WaterLettuce
 * @see Pothos
 * @see Ginger
 */
class WinterFactory : public PlantFactory {

public:
	/**
	 * @brief Creates a winter flower.
	 * @return Plant* Pointer to a newly created Sunflower.
	 */
	Plant* createFlower();

	/**
	 * @brief Creates a winter herb.
	 * @return Plant* Pointer to a newly created Rosemary plant.
	 */
	Plant* createHerb();

	/**
	 * @brief Creates a winter fruit.
	 * @return Plant* Pointer to a newly created Orange Tree.
	 */
	Plant* createFruit();

	/**
	 * @brief Creates a winter vegetable.
	 * @return Plant* Pointer to a newly created Cucumber plant.
	 */
	Plant* createVegetable();

	/**
	 * @brief Creates a winter succulent.
	 * @return Plant* Pointer to a newly created Christmas Cactus.
	 */
	Plant* createSucculent();

	/**
	 * @brief Creates a winter aquatic plant.
	 * @return Plant* Pointer to a newly created Water Lettuce.
	 */
	Plant* createAquatic();

	/**
	 * @brief Creates a winter indoor plant.
	 * @return Plant* Pointer to a newly created Pothos.
	 */
	Plant* createIndoor();

	/**
	 * @brief Creates a winter medicinal plant.
	 * @return Plant* Pointer to a newly created Ginger plant.
	 */
	Plant* createMedicinal();
};

#endif
