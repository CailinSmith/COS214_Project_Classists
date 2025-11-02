#ifndef RUBBERTREE_H
#define RUBBERTREE_H

#include "Indoor.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class RubberTree
 * @author Cailin Smith
 * @brief Represents a rubber tree indoor plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a rubber tree (Ficus elastica), a popular indoor
 * plant with glossy leaves and medium moisture requirements. Rubber trees
 * need thinning pruning to maintain shape and promote healthy growth.
 * They are best sold in spring.
 * 
 * @see Indoor
 * @see MediumMoisture
 * @see Thinning
 */
class RubberTree : public Indoor {

public:
	/**
	 * @brief Constructs a RubberTree plant.
	 * 
	 * Initializes the rubber tree with a maximum height of 300cm, medium moisture watering
	 * strategy, thinning pruning strategy, and spring as the best selling season.
	 */
	RubberTree() : Indoor(300, new MediumMoisture(), new Thinning(), "Rubber Tree", "Spring") {}
	
	/**
	 * @brief Gets the image path for the rubber tree plant.
	 * @return string Path to the rubber tree image.
	 */
	string getImagePath() override {
		return "assets/rubbertree.jpg";
	}
};

#endif
