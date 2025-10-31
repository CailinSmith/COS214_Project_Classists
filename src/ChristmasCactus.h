/**
 * @file ChristmasCactus.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef CHRISTMASCACTUS_H
#define CHRISTMASCACTUS_H

#include "Succulent.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class ChristmasCactus : public Succulent {

public:
	ChristmasCactus() : Succulent(60, new MediumMoisture(), new Thinning(), "Christmas Cactus", "Autumn"){}
	
	string getImagePath() override {
		return "assets/christmascactus.jpg";
	}
};

#endif
