/**
 * @file Lavender.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef LAVENDER_H
#define LAVENDER_H

#include "Herb.h"
#include "DryPlant.h"
#include "Reduction.h"

class Lavender : public Herb {
public:
	Lavender() : Herb(90, new DryPlant(), new Reduction(), "Lavender", "Summer") {}
	
	string getImagePath() override {
		return "assets/lavender.jpg";
	}
};

#endif
