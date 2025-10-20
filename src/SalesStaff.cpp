#include "SalesStaff.h"

SalesStaff::SalesStaff(string name) : Staff(name) {
    mediators.push_back(new SalesArea());
}

void SalesStaff::receive(string message) {
	// TODO - implement SalesStaff::receive
	throw "Not yet implemented";
}

void SalesStaff::handleRequest() {
	// TODO - implement SalesStaff::handleRequest
	throw "Not yet implemented";
}

string SalesStaff::getPosition() {
	return "Sales staff";
}