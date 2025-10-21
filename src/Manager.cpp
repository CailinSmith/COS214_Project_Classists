#include "Manager.h"

Manager::Manager(const string& str) : Staff(str){}

Manager::~Manager(){}

void Manager::send(string message, Staff* from) {
	// TODO - implement Manager::send
	throw "Not yet implemented";
}

void Manager::receive(string message) {
	// TODO - implement Manager::receive
	throw "Not yet implemented";
}

void Manager::handleRequest() {
	// TODO - implement Manager::handleRequest
	std::cout << "Manager: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}
