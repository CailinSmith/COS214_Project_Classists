#include "NurseryStaff.h"

NurseryStaff::NurseryStaff(string name) : Staff(name) {}

void NurseryStaff::handleRequest() {
	cout << getName() << " (" << getPosition() << ") handling mediator request." << endl;
}

string NurseryStaff::getPosition() {
	return "Nursery staff";
}

void NurseryStaff::update(const string& message) {
	cout << getName() << " (" << getPosition() << ") received observer update: " << message << endl;
}