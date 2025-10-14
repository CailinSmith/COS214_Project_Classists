#ifndef WINTER_H
#define WINTER_H

#include "SeasonState.h"
#include <string>
using namespace std;

class Winter : public SeasonState {
public:
	//this will set the season to spring and the factory to spring factory
	void change();
	string print();
};

#endif
