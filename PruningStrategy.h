#ifndef PRUNINGSTRATEGY_H
#define PRUNINGSTRATEGY_H

#include <string>
using namespace std;

class PruningStrategy {

public:
	virtual void prune() = 0;

	virtual string print() = 0;
};

#endif
