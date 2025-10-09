#ifndef CUCUMBER_H
#define CUCUMBER_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "Thinning.h"

class Cucumber : public Vegetable {
public:
	Cucumber() : Vegetable(300, new HighMoisture(), new Thinning(), "Cucumber") {}
};

#endif
