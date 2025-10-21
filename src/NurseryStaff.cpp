#include "NurseryStaff.h"

NurseryStaff::NurseryStaff(const string& str) : Staff(str){}

NurseryStaff::~NurseryStaff(){}

void NurseryStaff::send(string message, Staff* from) {
	// TODO - implement NurseryStaff::send
	throw "Not yet implemented";
}

void NurseryStaff::receive(string message) {
	// TODO - implement NurseryStaff::receive
	throw "Not yet implemented";
}

void NurseryStaff::handleRequest() {
	// TODO - implement NurseryStaff::handleRequest
	std::cout << "Nursery staff: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}
