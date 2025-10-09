#ifndef WINTER_H
#define WINTER_H

#include "SeasonState.h"
#include <string>
using namespace std;

class Winter : public SeasonState {
public:
	void change();
	string print();
};

#endif
