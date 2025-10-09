#ifndef THYME_H
#define THYME_H

#include "Herb.h"
#include "DryPlant.h"
#include "Thinning.h"

class Thyme : public Herb {

public:
	Thyme() : Herb(30, new DryPlant(), new Thinning(), "Thyme") {}
};

#endif
