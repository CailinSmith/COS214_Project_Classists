#ifndef THINNING_H
#define THINNING_H

#include "PruningStrategy.h"
#include <string>
using namespace std;

class Thinning : public PruningStrategy {

public:
	void prune(Plant* plant) ;

	string print() ;
};

#endif
