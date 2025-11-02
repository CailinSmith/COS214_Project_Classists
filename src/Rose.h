#ifndef ROSE_H
#define ROSE_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

/**
 * @class Rose
 * @author Cailin Smith
 * @brief Represents a rose flower plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a rose, one of the most popular flowering plants
 * with medium moisture requirements and deadheading pruning needs. Roses
 * require regular deadheading to promote continuous blooming. They are
 * best sold in spring.
 * 
 * @see Flower
 * @see MediumMoisture
 * @see DeadPruning
 */
class Rose : public Flower {
public:
	/**
	 * @brief Constructs a Rose plant.
	 * 
	 * Initializes the rose with a maximum height of 180cm, medium moisture watering strategy,
	 * dead pruning strategy, and spring as the best selling season.
	 */
	Rose() : Flower(180, new MediumMoisture(), new DeadPruning(), "Rose", "Spring") {}
	
	/**
	 * @brief Gets the image path for the rose plant.
	 * @return string Path to the rose image.
	 */
	string getImagePath() override {
		return "assets/rose.jpg";
	}
};

#endif
