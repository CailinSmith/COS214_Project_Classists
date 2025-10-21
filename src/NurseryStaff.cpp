#include "NurseryStaff.h"

NurseryStaff::NurseryStaff(string name) : Staff(name) {}

void NurseryStaff::handleRequest() {
	// TODO - implement NurseryStaff::handleRequest
	std::cout << "Nursery staff: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}

string NurseryStaff::getPosition() {
	return "Nursery staff";
}