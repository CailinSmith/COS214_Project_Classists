#ifndef REDUCTION_H
#define REDUCTION_H

#include "PruningStrategy.h"
#include <string>
using namespace std;

class Reduction : public PruningStrategy {
public:
	void prune(Plant* plant);
	string print();
};

#endif
