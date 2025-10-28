/**
 * @file Chrysanthemum.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef CHRYSANTHEMUM_H
#define CHRYSANTHEMUM_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

class Chrysanthemum : public Flower {
public:
	Chrysanthemum() : Flower(60, new MediumMoisture(), new DeadPruning(), "Chrysanthemum", "Autumn") {}
};

#endif
