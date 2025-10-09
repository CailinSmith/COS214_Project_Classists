#ifndef NOPRUNE_H
#define NOPRUNE_H

#include "PruningStrategy.h"
#include <string>
#include <iostream>
using namespace std;

class NoPrune : public PruningStrategy {

public:
	void prune(Plant* plant);

	string print();
};

#endif
