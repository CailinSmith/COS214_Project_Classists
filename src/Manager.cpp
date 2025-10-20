#include "Manager.h"

Manager::Manager(string name) : Staff(name) {
    mediators.push_back(new SalesArea());
    mediators.push_back(new NurseryArea());
}

void Manager::handleRequest() {
	// TODO - implement Manager::handleRequest
	throw "Not yet implemented";
}

string Manager::getPosition() {
    return "Manager";
}