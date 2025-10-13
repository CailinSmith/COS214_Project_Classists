/**
 * @file Indoor.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef INDOOR_H
#define INDOOR_H

#include "Plant.h"

class Indoor : public Plant {

public:
	Indoor(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Indoor", maxHeight, wateringStrat, pruningStrat, name) {}
};

#endif
