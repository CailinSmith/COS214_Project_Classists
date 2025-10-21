#include "NurseryStaff.h"

NurseryStaff::NurseryStaff(string name) : Staff(name) {}

void NurseryStaff::handleRequest() {
	cout << getName() << " (" << getPosition() << ") received a low-stock notification." << endl;
}

string NurseryStaff::getPosition() {
	return "Nursery staff";
}