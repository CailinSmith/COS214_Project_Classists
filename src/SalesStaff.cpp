#include "SalesStaff.h"
#include "Customer.h"
#include "StaffCheckoutCommand.h"

SalesStaff::SalesStaff(string name) : Staff(name) {}

pair<string, Receipt*> SalesStaff::handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) {
	// TODO - implement SalesStaff::handleRequest
	pair<string, Receipt*> result;
	if (requestType == "Checkout" && order){
		StaffCheckoutCommand cmd(*order);
		cmd.execute();
		Receipt* receipt = cmd.getReceipt();
		if(receipt){
			// Make a deep copy of the receipt to return to the caller. The
			// StaffCheckoutCommand owns its receipt and will delete it in its
			// destructor, so we must return an independent copy to avoid
			// dangling pointers/use-after-free.
			result.first = receipt->toString();
			result.second = new Receipt(*receipt);
			// The checkout command transferred ownership; we created a copy to
			// return to the caller, so delete the original to avoid a leak.
			delete receipt;
		}
		else
			result.first = "Error generating receipt\n";
		return result;
	}
	else if(next){
		return next->handleRequest(requestType, plant, order, flags);
	}
	result.first = "No staff could handle '" + requestType + "'\n";
	return result;
}

string SalesStaff::getPosition() {
	return "Sales staff";
}