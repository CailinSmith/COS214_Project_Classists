#ifndef SUMMER_H
#define SUMMER_H

#include "SeasonState.h"
#include <string>
using namespace std;

class Summer : public SeasonState {
public:
//this will set the season to autumn and the factory to autumn factory
	void change();
	string print();
};

#endif
