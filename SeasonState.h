#ifndef SEASON STATE_H
#define SEASON STATE_H

class SeasonState {

public:
	virtual void change() = 0;

	virtual string print() = 0;
};

#endif
