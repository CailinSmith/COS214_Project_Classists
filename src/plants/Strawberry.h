#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class Strawberry : public Fruit {

public:
	Strawberry() : Fruit(25, new MediumMoisture(), new Thinning(), "Strawberry") {}
};

#endif
