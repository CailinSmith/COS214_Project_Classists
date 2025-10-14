#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"
#include "Plant.h"
#include "ReadyForSaleState.h"
#include "DyingState.h"

#include <string>

using namespace std;

class MatureState : public PlantState {
public:
	virtual void change(Plant* plant) override;
	virtual string print() override;
};

#endif