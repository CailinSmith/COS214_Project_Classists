/**
 * @file Thyme.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef THYME_H
#define THYME_H

#include "Herb.h"
#include "DryPlant.h"
#include "Thinning.h"

class Thyme : public Herb {

public:
	Thyme() : Herb(30, new DryPlant(), new Thinning(), "Thyme", "Summer") {}
	
	string getImagePath() override {
		return "assets/thyme.jpg";
	}
};

#endif
