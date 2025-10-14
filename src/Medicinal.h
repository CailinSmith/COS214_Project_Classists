/**
 * @file Medicinal.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef MEDICINAL_H
#define MEDICINAL_H

#include "Plant.h"

class Medicinal : public Plant {

public:
	Medicinal(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) : 
	Plant("Medicinal", maxHeight, wateringStrat, pruningStrat, name) {}

	virtual float baseCost() override;
};

#endif
