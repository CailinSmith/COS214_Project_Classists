#ifndef PANSY_H
#define PANSY_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

class Pansy : public Flower {
public:
	Pansy() : Flower(25, new MediumMoisture(), new DeadPruning(), "Pansy") {}
};

#endif
