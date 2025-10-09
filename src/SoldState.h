#ifndef SOLDSTATE_H
#define SOLDSTATE_H

#include "PlantState.h"
#include <string>
using namespace std;

class SoldState : public PlantState {


public:
	void change();

	string print();
};

#endif
