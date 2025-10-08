#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"
#include <string>
using namespace std;

class MatureState : public PlantState {
public:
	void change();
	string print();
};

#endif
