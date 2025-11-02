#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"

/**
 * @class PlantFactory
 * @author Cailin Smith
 * @brief Abstract factory for creating different types of plants.
 * Design Pattern: Abstract Factory
 * Participant: AbstractFactory
 * 
 * This abstract class defines the interface for creating various plant types.
 * Concrete factory subclasses (SpringFactory, SummerFactory, etc.) implement
 * these methods to create season-specific plant varieties. Each factory method
 * creates a different category of plant.
 * 
 * @see Plant
 * @see SpringFactory
 * @see SummerFactory
 * @see AutumnFactory
 * @see WinterFactory
 */
class PlantFactory {

public:
	/**
	 * @brief Virtual destructor for the PlantFactory.
	 */
	virtual ~PlantFactory() {}

	/**
	 * @brief Creates a flower plant.
	 * @return Plant* Pointer to a newly created flower plant.
	 */
	virtual Plant* createFlower() = 0;

	/**
	 * @brief Creates an herb plant.
	 * @return Plant* Pointer to a newly created herb plant.
	 */
	virtual Plant* createHerb() = 0;

	/**
	 * @brief Creates a fruit plant.
	 * @return Plant* Pointer to a newly created fruit plant.
	 */
	virtual Plant* createFruit() = 0;

	/**
	 * @brief Creates a vegetable plant.
	 * @return Plant* Pointer to a newly created vegetable plant.
	 */
	virtual Plant* createVegetable() = 0;

	/**
	 * @brief Creates a succulent plant.
	 * @return Plant* Pointer to a newly created succulent plant.
	 */
	virtual Plant* createSucculent() = 0;

	/**
	 * @brief Creates an aquatic plant.
	 * @return Plant* Pointer to a newly created aquatic plant.
	 */
	virtual Plant* createAquatic() = 0;

	/**
	 * @brief Creates an indoor plant.
	 * @return Plant* Pointer to a newly created indoor plant.
	 */
	virtual Plant* createIndoor() = 0;

	/**
	 * @brief Creates a medicinal plant.
	 * @return Plant* Pointer to a newly created medicinal plant.
	 */
	virtual Plant* createMedicinal() = 0;
};

#endif
