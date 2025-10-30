/**
 * @file Strawberry.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class Strawberry : public Fruit {

public:
	Strawberry() : Fruit(25, new MediumMoisture(), new Thinning(), "Strawberry", "Spring") {}
	
	string getImagePath() override {
		return "assets/strawberry.jpg";
	}
};

#endif
