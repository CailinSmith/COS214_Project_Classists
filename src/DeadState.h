#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantState.h"
#include "Plant.h"
#include <string>

using namespace std;

class DeadState : public PlantState {
public:
	virtual void change(Plant* plant) override;
	virtual string print() override;
};

#endif