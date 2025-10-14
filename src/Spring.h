#ifndef SPRING_H
#define SPRING_H

#include "SeasonState.h"
#include <string>
using namespace std;

class Spring : public SeasonState {
public:
	//this will set the season to summer and the factory to summer factory
	//I temporarily implemented this so that i can test command
	void change() {}
	string print() { return "Spring"; }
};

#endif
