/**
 * @file WaterLettuce.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef WATERLETTUCE_H
#define WATERLETTUCE_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "Thinning.h"

class WaterLettuce : public Aquatic {

public:
	WaterLettuce() : Aquatic(20, new HighMoisture(), new Thinning(), "Water Lettuce", "Summer") {}
	
	string getImagePath() override {
		return "assets/waterlettuce.jpg";
	}
};

#endif
