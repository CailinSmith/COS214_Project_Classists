#ifndef APPLETREE_H
#define APPLETREE_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class AppleTree : public Fruit {
public:
	AppleTree() : Fruit(600, new MediumMoisture(), new Thinning(), "Apple Tree") {}
};

#endif
