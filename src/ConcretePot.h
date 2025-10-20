#ifndef CONCRETEPOT_H
#define CONCRETEPOT_H

#include "Decorator.h"

class ConcretePot : public Decorator
{
public:
	ConcretePot(Product* plant);
	~ConcretePot();
	float calculateCost(string currentSeason);
	string getSummary();
	string getName();
};

#endif // CONCRETEPOT_H

