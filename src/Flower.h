/**
 * @file Flower.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {
	
public:
	Flower(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Flower", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	virtual ~Flower() {}
	virtual float baseCost() override;
	virtual float seasonCost(string curSeason) override;
};

#endif
