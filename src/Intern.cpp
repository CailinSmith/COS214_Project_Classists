#include "Intern.h"

Intern::Intern(string name) : Staff(name) {}

void Intern::handleRequest() {
	// TODO - implement Intern::handleRequest
	std::cout << "Intern: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}

string Intern::getPosition() {
    return "Intern";
}