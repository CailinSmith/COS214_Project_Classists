/**
 * @file Vegetable.h
 * @author Cailin Smith
 * @date 2025-10-09
 */
#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "Plant.h"

class Vegetable : public Plant {
public:
	Vegetable(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Vegetable", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	virtual float baseCost() override;
	virtual float seasonCost(string curSeason) override;
};

#endif
