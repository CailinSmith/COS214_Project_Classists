/**
 * @file Vegatable.h
 * @author Cailin Smith
 * @date 2025-10-09
 */
#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "Plant.h"

class Vegetable : public Plant {
public:
	Vegetable(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Vegetable", maxHeight, wateringStrat, pruningStrat, name) {}
};

#endif
