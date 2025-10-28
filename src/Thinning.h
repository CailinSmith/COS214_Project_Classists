/**
 * @file Thinning.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

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
