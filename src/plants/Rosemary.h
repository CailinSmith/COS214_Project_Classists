#ifndef ROSEMARY_H
#define ROSEMARY_H

#include "Herb.h"
#include "DryPlant.h"
#include "Thinning.h"

class Rosemary : public Herb {
public:
	Rosemary() : Herb(150, new DryPlant(), new Thinning(), "Rosemary") {}
};

#endif
