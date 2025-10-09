#ifndef GINGER_H
#define GINGER_H

#include "Medicinal.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class Ginger : public Medicinal {

public:
	Ginger() : Medicinal(120, new MediumMoisture(), new Thinning(), "Ginger") {}
};

#endif
