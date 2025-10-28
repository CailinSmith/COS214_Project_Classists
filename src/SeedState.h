#ifndef SEEDSTATE_H
#define SEEDSTATE_H

#include "PlantState.h"
#include "Plant.h"
#include "SeedlingState.h"

#include <string>
using namespace std;

class SeedState : public PlantState {
public:
	virtual void change(Plant* plant) override;
	virtual string print() override;
};

#endif
