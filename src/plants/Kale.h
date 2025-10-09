#ifndef KALE_H
#define KALE_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "NoPrune.h"

class Kale : public Vegetable {

public:
	Kale() : Vegetable(60, new HighMoisture(), new NoPrune(), "Kale") {}
};

#endif
