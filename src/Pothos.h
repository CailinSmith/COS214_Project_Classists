#ifndef POTHOS_H
#define POTHOS_H

#include "Indoor.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class Pothos
 * @author Cailin Smith
 * @brief Represents a Pothos indoor plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Pothos, a popular indoor trailing plant with medium
 * moisture requirements and thinning pruning needs. Pothos plants are hardy
 * and easy to care for, making them perfect for beginners. They are best sold
 * in winter.
 * 
 * @see Indoor
 * @see MediumMoisture
 * @see Thinning
 */
class Pothos : public Indoor {

public:
	/**
	 * @brief Constructs a Pothos plant.
	 * 
	 * Initializes the Pothos with a maximum height of 300cm, medium moisture watering strategy,
	 * thinning pruning strategy, and winter as the best selling season.
	 */
	Pothos() : Indoor(300, new MediumMoisture(), new Thinning(), "Pothos", "Winter") {}
	
	/**
	 * @brief Gets the image path for the Pothos plant.
	 * @return string Path to the Pothos image.
	 */
	string getImagePath() override {
		return "assets/pothos.jpg";
	}
};

#endif
