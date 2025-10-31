/**
 * @file Lettuce.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef LETTUCE_H
#define LETTUCE_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "NoPrune.h"

class Lettuce : public Vegetable {
public:
	Lettuce() : Vegetable(30, new HighMoisture(), new NoPrune(), "Lettuce", "Spring") {}
	
	string getImagePath() override {
		return "assets/lettuce.jpg";
	}
};

#endif
