#ifndef SPRING_H
#define SPRING_H

#include "SeasonState.h"
#include <string>
using namespace std;

class Spring : public SeasonState {
public:
	void change();
	string print();
};

#endif
