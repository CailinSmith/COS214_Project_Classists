#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantState.h"
#include <string>
using namespace std;

class DeadState : public PlantState {

public:
	void change();

	string print();
};

#endif
