#ifndef WATERLILY_H
#define WATERLILY_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "DeadPruning.h"

class WaterLily : public Aquatic {

public:
	WaterLily() : Aquatic(20, new HighMoisture(), new DeadPruning(), "Water Lily") {}
};

#endif
