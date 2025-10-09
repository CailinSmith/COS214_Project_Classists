#ifndef BASIL_H
#define BASIL_H

#include "Herb.h"
#include "HighMoisture.h"
#include "Thinning.h"

class Basil : public Herb {
public:
	Basil() : Herb(60, new HighMoisture(), new Thinning(), "Basil") {}
};

#endif
