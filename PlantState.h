#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>
using namespace std;
class PlantState {

public:
	virtual void change() = 0;

	virtual string print() = 0;
};

#endif
