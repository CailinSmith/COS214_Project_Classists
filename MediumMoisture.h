#ifndef MEDIUMMOISTURE_H
#define MEDIUMMOISTURE_H

#include "WateringStrategy.h"
#include <string>
using namespace std;

class MediumMoisture : public WateringStrategy {
public:
	void water();
	string print();
};

#endif
