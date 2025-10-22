#include "NurseryStaff.h"

NurseryStaff::NurseryStaff(string name) : Staff(name) {}

void NurseryStaff::handleRequest() {
	// TODO - implement NurseryStaff::handleRequest
	cout << getName() << " (" << getPosition() << ") handling mediator request." << endl;
	std::cout << "Nursery staff: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}

string NurseryStaff::getPosition() {
	return "Nursery staff";
}

void NurseryStaff::update(const string& message) {
	cout << getName() << " (" << getPosition() << ") received observer update: " << message << endl;
}