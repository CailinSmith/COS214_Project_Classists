#ifndef PEACELILY_H
#define PEACELILY_H

#include "Indoor.h"
#include "HighMoisture.h"
#include "DeadPruning.h"

/**
 * @class PeaceLily
 * @author Cailin Smith
 * @brief Represents a Peace Lily indoor plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Peace Lily plant, which is an indoor plant with high moisture
 * watering requirements and dead heading pruning strategy. The plant has a maximum height
 * of 120cm and is available for sale during the Spring season.
 * 
 * @see Indoor
 * @see HighMoisture
 * @see DeadPruning
 */
class PeaceLily : public Indoor {

public:
	/**
	 * @brief Constructs a PeaceLily plant with default characteristics.
	 * 
	 * Initializes the Peace Lily with a maximum height of 120cm, high moisture watering
	 * strategy, dead heading pruning strategy, and sets it as available for sale in Spring.
	 */
	PeaceLily() : Indoor(120, new HighMoisture(), new DeadPruning(), "Peace Lily", "Spring") {}
	
	/**
	 * @brief Gets the image path for the Peace Lily plant.
	 * @return string The path to the Peace Lily image asset.
	 */
	string getImagePath() override {
		return "assets/peacelily.jpg";
	}
};

#endif
