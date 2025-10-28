#ifndef SEASONSTATE_H
#define SEASONSTATE_H

#include <string>

class Nursery; 

class SeasonState {
public:
	virtual ~SeasonState() {}
	virtual void change(Nursery* nursery) = 0;
	virtual std::string print() = 0;
};

#endif