#include "SalesStaff.h"

SalesStaff::SalesStaff(string name) : Staff(name) {}

void SalesStaff::handleRequest() {
	// TODO - implement SalesStaff::handleRequest
	std::cout << "Sales staff: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}

string SalesStaff::getPosition() {
	return "Sales staff";
}