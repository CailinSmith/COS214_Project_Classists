#ifndef SUMMER_H
#define SUMMER_H

#include "SeasonState.h"
#include <string>
using namespace std;

class Summer : public SeasonState {
public:
	void change();
	string print();
};

#endif
