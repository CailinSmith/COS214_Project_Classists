#ifndef DYINGSTATE_H
#define DYINGSTATE_H

#include "PlantState.h"
#include <string>
using namespace std;

class DyingState : public PlantState {

public:
	void change();

	string print();
};

#endif
