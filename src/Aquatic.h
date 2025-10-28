/**
 * @file Aquatic.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef AQUATIC_H
#define AQUATIC_H

#include "Plant.h"

class Aquatic : public Plant {

public:
	Aquatic(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Aquatic", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	virtual float baseCost() override;
};

#endif
