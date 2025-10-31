/**
 * @file BarrelCactus.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef BARRELCACTUS_H
#define BARRELCACTUS_H

#include "Succulent.h"
#include "DryPlant.h"
#include "NoPrune.h"

class BarrelCactus : public Succulent {

public:
	BarrelCactus() : Succulent(120, new DryPlant(), new NoPrune(), "Barrel Cactus", "Spring") {}
	
	string getImagePath() override {
		return "assets/barrelcactus.jpg";
	}
};

#endif
