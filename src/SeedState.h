#ifndef SEEDSTATE_H
#define SEEDSTATE_H

#include "PlantState.h"
#include <string>
using namespace std;

class SeedState : public PlantState {

public:
	void change();

	string print();
};

#endif
