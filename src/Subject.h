#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject {

public:
	virtual void notifyStaff(std::string message) = 0;
};

#endif
