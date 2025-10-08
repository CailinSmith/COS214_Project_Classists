#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantState.h"
#include <string>
using namespace std;

class GrowingState : public PlantState {
	
public:
	void change();
	string print();
};

#endif
