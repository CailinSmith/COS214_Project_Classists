#include "Intern.h"

Intern::Intern(string name) : Staff(name) {
    mediators.push_back(new NurseryArea());
}

void Intern::handleRequest() {
	// TODO - implement Intern::handleRequest
	throw "Not yet implemented";
}

string Intern::getPosition() {
    return "Intern";
}