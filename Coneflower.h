#ifndef CONEFLOWER_H
#define CONEFLOWER_H

#include "Medicinal.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

class Coneflower : public Medicinal {

public:
	Coneflower() : Medicinal(90, new MediumMoisture(), new DeadPruning(), "Coneflower") {}
};

#endif
