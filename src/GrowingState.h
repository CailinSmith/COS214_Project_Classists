#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantState.h"
#include "Plant.h"
#include "MatureState.h"
#include "DyingState.h"

#include <string>

using namespace std;

class GrowingState : public PlantState {
public:
	virtual void change(Plant* plant) override;
	virtual string print() override;
};

#endif