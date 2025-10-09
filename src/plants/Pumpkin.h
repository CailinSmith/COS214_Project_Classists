#ifndef PUMPKIN_H
#define PUMPKIN_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "Thinning.h"

class Pumpkin : public Vegetable {
public:
	Pumpkin() : Vegetable(60, new HighMoisture(), new Thinning(), "Pumpkin") {}
};

#endif
