#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"
#include <string>
using namespace std;

class SeedlingState : public PlantState {
public:
	void change();
	string print();
};

#endif
