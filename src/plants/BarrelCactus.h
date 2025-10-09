#ifndef BARRELCACTUS_H
#define BARRELCACTUS_H

#include "Succulent.h"
#include "DryPlant.h"
#include "NoPrune.h"

class BarrelCactus : public Succulent {

public:
	BarrelCactus() : Succulent(120, new DryPlant(), new NoPrune(), "Barrel Cactus") {}
};

#endif
