#ifndef NOPRUNE_H
#define NOPRUNE_H

#include "PruningStrategy.h"
#include <string>
using namespace std;

class NoPrune : public PruningStrategy {

public:
	void prune();

	string print();
};

#endif
