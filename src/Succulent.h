/**
 * @file Succulent.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"

class Succulent : public Plant {

public:
	Succulent(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Succulent", maxHeight, wateringStrat, pruningStrat, name) {}
};

#endif
