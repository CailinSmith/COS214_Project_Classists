/**
 * @file Basil.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef BASIL_H
#define BASIL_H

#include "Herb.h"
#include "HighMoisture.h"
#include "Thinning.h"

class Basil : public Herb {
public:
	Basil() : Herb(60, new HighMoisture(), new Thinning(), "Basil", "Summer") {}
	
	string getImagePath() override {
		return "assets/basil.jpg";
	}
};

#endif
