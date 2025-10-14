#ifndef DYINGSTATE_H
#define DYINGSTATE_H

#include "PlantState.h"
#include "Plant.h"
#include "DeadState.h"
#include "MatureState.h"
#include "GrowingState.h"

#include <string>

using namespace std;

class DyingState : public PlantState {
public:
	virtual void change(Plant* plant) override;
	virtual string print() override;
};

#endif