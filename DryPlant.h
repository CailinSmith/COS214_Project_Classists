#ifndef DRYPLANT_H
#define DRYPLANT_H

#include "WateringStrategy.h"
#include <string>
using namespace std;

class DryPlant : public WateringStrategy {
public:
	void water();
	string print();
};

#endif
