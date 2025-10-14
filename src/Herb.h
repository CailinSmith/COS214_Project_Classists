/**
 * @file Herb.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef HERB_H
#define HERB_H

#include "Plant.h"

class Herb : public Plant {
public:
	Herb(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Herb", maxHeight, wateringStrat, pruningStrat, name) {}

	virtual float baseCost() override;
	
};

#endif
