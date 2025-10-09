#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {
	
public:
	Flower(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Flower", maxHeight, wateringStrat, pruningStrat, name) {}
};

#endif
