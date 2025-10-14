#ifndef SEASONSTATE_H
#define SEASONSTATE_H

#include <string>

class SeasonState {

public:
	virtual void change() = 0;

	virtual std::string print() = 0;
};

#endif
