/**
 * @file PruningStrategy.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef PRUNINGSTRATEGY_H
#define PRUNINGSTRATEGY_H

#include <string>
using namespace std;

class Plant;

class PruningStrategy {

public:
	virtual ~PruningStrategy() {}
	
	virtual void prune(Plant* plant) = 0;

	virtual string print() = 0;
};

#endif
