#ifndef WATERLILY_H
#define WATERLILY_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "DeadPruning.h"

/**
 * @class WaterLily
 * @author Cailin Smith
 * @brief Represents a water lily aquatic plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a water lily, an iconic floating aquatic plant with
 * high moisture requirements and deadheading pruning needs. Water lilies are
 * prized for their beautiful flowers that float on the water surface. They
 * require deadheading to promote continuous blooming and are best sold in summer.
 * 
 * @see Aquatic
 * @see HighMoisture
 * @see DeadPruning
 */
class WaterLily : public Aquatic {

public:
	/**
	 * @brief Constructs a WaterLily plant.
	 * 
	 * Initializes the water lily with a maximum height of 20cm, high moisture watering
	 * strategy, dead pruning strategy, and summer as the best selling season.
	 */
	WaterLily() : Aquatic(20, new HighMoisture(), new DeadPruning(), "Water Lily", "Summer") {}
	
	/**
	 * @brief Gets the image path for the water lily plant.
	 * @return string Path to the water lily image.
	 */
	string getImagePath() override {
		return "assets/waterlily.jpg";
	}
};

#endif
