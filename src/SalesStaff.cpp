#include "SalesStaff.h"

SalesStaff::SalesStaff(string name) : Staff(name) {}

void SalesStaff::handleRequest() {
	// TODO - implement SalesStaff::handleRequest
	throw "Not yet implemented";
}

string SalesStaff::getPosition() {
	return "Sales staff";
}