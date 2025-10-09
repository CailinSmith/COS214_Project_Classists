#ifndef AUTUMN_H
#define AUTUMN_H

#include "SeasonState.h"
#include <string>
using namespace std;

class Autumn : public SeasonState {

public:
	void change();

	string print();
};

#endif
