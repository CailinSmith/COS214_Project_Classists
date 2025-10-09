#ifndef LETTUCE_H
#define LETTUCE_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "NoPrune.h"

class Lettuce : public Vegetable {
public:
	Lettuce() : Vegetable(30, new HighMoisture(), new NoPrune(), "Lettuce") {}
};

#endif
