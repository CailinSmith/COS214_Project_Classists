#ifndef WATERLETTUCE_H
#define WATERLETTUCE_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "Thinning.h"

/**
 * @class WaterLettuce
 * @author Cailin Smith
 * @brief Represents a water lettuce aquatic plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents water lettuce, a floating aquatic plant with
 * high moisture requirements and thinning pruning needs. Water lettuce
 * forms rosettes of velvety leaves on the water surface and requires
 * regular thinning to prevent overgrowth. Best sold in summer.
 * 
 * @see Aquatic
 * @see HighMoisture
 * @see Thinning
 */
class WaterLettuce : public Aquatic {

public:
	/**
	 * @brief Constructs a WaterLettuce plant.
	 * 
	 * Initializes the water lettuce with a maximum height of 20cm, high moisture watering
	 * strategy, thinning pruning strategy, and summer as the best selling season.
	 */
	WaterLettuce() : Aquatic(20, new HighMoisture(), new Thinning(), "Water Lettuce", "Summer") {}
	
	/**
	 * @brief Gets the image path for the water lettuce plant.
	 * @return string Path to the water lettuce image.
	 */
	string getImagePath() override {
		return "assets/waterlettuce.jpg";
	}
};

#endif
