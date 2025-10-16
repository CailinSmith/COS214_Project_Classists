#include "Intern.h"

Intern::Intern(const string& str) : Staff(str){}

Intern::~Intern(){}

void Intern::send(string message, Staff* from) {
	// TODO - implement Intern::send
	throw "Not yet implemented";
}

void Intern::receive(string message) {
	// TODO - implement Intern::receive
	throw "Not yet implemented";
}

void Intern::handleRequest() {
	// TODO - implement Intern::handleRequest
	std::cout << "Intern: " << name << " handled request.";
	if(next)
		next->handleRequest();
}
