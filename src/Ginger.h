/**
 * @file Ginger.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef GINGER_H
#define GINGER_H

#include "Medicinal.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class Ginger : public Medicinal {

public:
	Ginger() : Medicinal(120, new MediumMoisture(), new Thinning(), "Ginger", "Summer") {}
	
	string getImagePath() override {
		return "assets/ginger.jpg";
	}
};

#endif
