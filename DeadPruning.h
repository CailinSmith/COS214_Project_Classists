#ifndef DEADPRUNING_H
#define DEADPRUNING_H

#include "PruningStrategy.h"
#include <string>
using namespace std;

class DeadPruning : public PruningStrategy {
public:
	void prune();
	string print();
};

#endif
