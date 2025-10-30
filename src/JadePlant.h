/**
 * @file JadePlant.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef JADEPLANT_H
#define JADEPLANT_H

#include "Succulent.h"
#include "DryPlant.h"
#include "Thinning.h"

class JadePlant : public Succulent {
public:
	JadePlant() : Succulent(120, new DryPlant(), new Thinning(), "JadePlant", "Spring") {}
	
	string getImagePath() override {
		return "assets/jadeplant.jpg";
	}
};

#endif
