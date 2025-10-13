#ifndef SEASON STATE_H
#define SEASON STATE_H

#include <string>

class SeasonState {

public:
	virtual void change() = 0;

	virtual std::string print() = 0;
};

#endif
