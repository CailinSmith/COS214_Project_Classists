#ifndef WATERHYACINTH_H
#define WATERHYACINTH_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "Thinning.h"

/**
 * @class WaterHyacinth
 * @author Cailin Smith
 * @brief Represents a water hyacinth aquatic plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a water hyacinth, a floating aquatic plant with
 * high moisture requirements and thinning pruning needs. Water hyacinths
 * are known for their beautiful purple flowers and rapid growth. They
 * are best sold in summer.
 * 
 * @see Aquatic
 * @see HighMoisture
 * @see Thinning
 */
class WaterHyacinth : public Aquatic {

public:
	/**
	 * @brief Constructs a WaterHyacinth plant.
	 * 
	 * Initializes the water hyacinth with a maximum height of 30cm, high moisture watering
	 * strategy, thinning pruning strategy, and summer as the best selling season.
	 */
	WaterHyacinth() : Aquatic(30, new HighMoisture(), new Thinning(), "Water Hyacinth", "Summer") {}
	
	/**
	 * @brief Gets the image path for the water hyacinth plant.
	 * @return string Path to the water hyacinth image.
	 */
	string getImagePath() override {
		return "assets/waterhyacinth.jpg";
	}
};

#endif
