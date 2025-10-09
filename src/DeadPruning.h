#ifndef DEADPRUNING_H
#define DEADPRUNING_H

#include "PruningStrategy.h"
#include "Plant.h"
#include <string>
#include <iostream>
using namespace std;

class DeadPruning : public PruningStrategy {
public:
	void prune(Plant* plant);
	string print();
};

#endif
