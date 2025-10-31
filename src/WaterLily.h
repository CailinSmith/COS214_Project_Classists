/**
 * @file WaterLily.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef WATERLILY_H
#define WATERLILY_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "DeadPruning.h"

class WaterLily : public Aquatic {

public:
	WaterLily() : Aquatic(20, new HighMoisture(), new DeadPruning(), "Water Lily", "Summer") {}
	
	string getImagePath() override {
		return "assets/waterlily.jpg";
	}
};

#endif
