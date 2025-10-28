#ifndef PLANTSTATE_H
#define PLANTSTATE_H

// Forward declaration to avoid circular dependency with Plant
class Plant;

#include <string>
using namespace std;

class PlantState {
public:
	virtual ~PlantState() {}
	virtual void change(Plant* plant) = 0;
	virtual string print() = 0;
};

#endif
