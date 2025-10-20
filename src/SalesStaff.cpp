#include "SalesStaff.h"

SalesStaff::SalesStaff(const string& str) : Staff(str){}

SalesStaff::~SalesStaff(){}

void SalesStaff::send(string message, Staff* from) {
	// TODO - implement SalesStaff::send
	throw "Not yet implemented";
}

void SalesStaff::receive(string message) {
	// TODO - implement SalesStaff::receive
	throw "Not yet implemented";
}

void SalesStaff::handleRequest() {
	// TODO - implement SalesStaff::handleRequest
	std::cout << "Sales staff: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}
