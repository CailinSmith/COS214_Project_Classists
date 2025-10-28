/**
 * @file Sunflower.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "NoPrune.h"

class Sunflower : public Flower {

public:
	Sunflower() : Flower(400, new MediumMoisture(), new NoPrune(), "Sunflower", "Summer") {}
};

#endif
