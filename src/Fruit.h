/**
 * @file Fruit.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef FRUIT_H
#define FRUIT_H

#include "Plant.h"

class Fruit : public Plant {

public:
	Fruit(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Fruit", maxHeight, wateringStrat, pruningStrat, name) {}
};

#endif
