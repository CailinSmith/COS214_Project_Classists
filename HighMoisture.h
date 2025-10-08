#ifndef HIGHMOISTURE_H
#define HIGHMOISTURE_H

#include "WateringStrategy.h"
#include <string>
using namespace std;

class HighMoisture : public WateringStrategy {
public:
	void water();
	string print();
};

#endif
