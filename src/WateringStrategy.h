#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include <string>
using namespace std;

class Plant;

class WateringStrategy {

public:
	virtual ~WateringStrategy() {}
	
	virtual void water(Plant* plant) = 0;

	virtual string print() = 0;
};

#endif
