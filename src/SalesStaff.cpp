#include "SalesStaff.h"
#include "Customer.h"
#include "StaffCheckoutCommand.h"

SalesStaff::SalesStaff(string name) : Staff(name) {}

string SalesStaff::handleRequest(Customer* customer, const string& requestType, Plant* plant, std::vector<Product*>* order) {
	// TODO - implement SalesStaff::handleRequest
	if (requestType == "Checkout" && order){
		StaffCheckoutCommand cmd(*order);
		cmd.execute();
		Receipt* receipt = cmd.getReceipt();
		if(receipt)
			customer->setReceipt(*receipt);
		return receipt->toString();
	}
	else if(next){
		return next->handleRequest(customer, requestType, plant, order);
	}
	return "No staff could handle '" + requestType + "'\n";
}

string SalesStaff::getPosition() {
	return "Sales staff";
}