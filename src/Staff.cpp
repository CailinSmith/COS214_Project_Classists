#include "Staff.h"

Staff::Staff(const string& str) : name(str), next(NULL){}

Staff::~Staff(){}

void Staff::setNext(Staff* nextStaff){
	next = nextStaff;
}

string Staff::getName() {
	return this->name;
}
