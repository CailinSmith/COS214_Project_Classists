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

/**
 * @class SpringFactory
 * @author Cailin Smith
 * @brief Concrete factory for creating spring-season plants.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteFactory
 * 
 * This class implements the PlantFactory interface to create plants that
 * are appropriate for the spring season. Each creation method returns a
 * specific spring plant variety (Rose, Basil, Tomato, Lettuce, Jade Plant,
 * Water Lily, Snake Plant, Aloe Vera).
 * 
 * @see PlantFactory
 * @see Rose
 * @see Basil
 * @see Tomato
 * @see Lettuce
 * @see JadePlant
 * @see WaterLily
 * @see SnakePlant
 * @see AloeVera
 */
class SpringFactory : public PlantFactory {
public:
	/**
	 * @brief Creates a spring flower.
	 * @return Plant* Pointer to a newly created Rose.
	 */
	Plant* createFlower();
	
	/**
	 * @brief Creates a spring herb.
	 * @return Plant* Pointer to a newly created Basil plant.
	 */
	Plant* createHerb();
	
	/**
	 * @brief Creates a spring fruit.
	 * @return Plant* Pointer to a newly created Tomato plant.
	 */
	Plant* createFruit();
	
	/**
	 * @brief Creates a spring vegetable.
	 * @return Plant* Pointer to a newly created Lettuce plant.
	 */
	Plant* createVegetable();

	/**
	 * @brief Creates a spring succulent.
	 * @return Plant* Pointer to a newly created Jade Plant.
	 */
	Plant* createSucculent();

	/**
	 * @brief Creates a spring aquatic plant.
	 * @return Plant* Pointer to a newly created Water Lily.
	 */
	Plant* createAquatic();

	/**
	 * @brief Creates a spring indoor plant.
	 * @return Plant* Pointer to a newly created Snake Plant.
	 */
	Plant* createIndoor();

	/**
	 * @brief Creates a spring medicinal plant.
	 * @return Plant* Pointer to a newly created Aloe Vera.
	 */
	Plant* createMedicinal();
};

#endif
