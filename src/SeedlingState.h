#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"
#include "Plant.h"
#include "GrowingState.h"

#include <string>

using namespace std;

class SeedlingState : public PlantState {
public:
	virtual void change(Plant* plant) override;
	virtual string print() override;
};

#endif