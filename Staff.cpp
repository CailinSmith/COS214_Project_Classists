#include "Staff.h"

Staff::Staff(const string& str) : name(str){}

Staff::~Staff(){
	/*
	if(next){
		delete next;
		next = NULL;
	}
	*/
}

void Staff::setNext(Staff* nextStaff){
	next = nextStaff;
}

string Staff::getName() {
	return this->name;
}
