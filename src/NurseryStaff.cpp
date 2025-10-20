#include "NurseryStaff.h"

NurseryStaff::NurseryStaff(string name) : Staff(name) {
    mediators.push_back(new NurseryArea());
}

void NurseryStaff::handleRequest() {
	// TODO - implement NurseryStaff::handleRequest
	throw "Not yet implemented";
}

string NurseryStaff::getPosition() {
	return "Nursery staff";
}