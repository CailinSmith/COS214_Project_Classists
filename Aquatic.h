#ifndef AQUATIC_H
#define AQUATIC_H

#include "Plant.h"

class Aquatic : public Plant {

public:
	Aquatic(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Aquatic", maxHeight, wateringStrat, pruningStrat, name) {}
};

#endif
