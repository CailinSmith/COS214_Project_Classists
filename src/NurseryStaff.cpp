#include "NurseryStaff.h"
#include "Customer.h"

NurseryStaff::NurseryStaff(string name) : Staff(name){}

pair<string, Receipt*> NurseryStaff::handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) {
	// TODO - implement NurseryStaff::handleRequest
	pair<string, Receipt*> result;
	result.second = nullptr;

	if(requestType == "CheckStock" && plant){
		// Use the existing Nursery singleton's InventoryManager. Do not create/delete
		// a temporary InventoryManager here — that can lead to a dangling pointer
		// if the Nursery singleton was initialised with the passed manager.
		Nursery* nursery = Nursery::getInstance();
		if (!nursery) {
			result.first = "Error: Nursery has not been initialised with an InventoryManager.\n";
			return result;
		}
		InventoryManager* im = nursery->getInventoryManager();
		if (!im) {
			result.first = "Error: Nursery's InventoryManager is null.\n";
			return result;
		}
        StaffCheckStockCommand* checkStockCommand = new StaffCheckStockCommand(plant, im);
        setCommand(checkStockCommand); 
		command->execute();
		result.first = to_string(checkStockCommand->getStock()) + " units of " + plant->getName() + " are in stock.\n"; //not using command->getStock() as StaffCommand has no such method
		return result;
	}
	else if(requestType == "AskInfo" && plant){
        GetInfoCommand* getInfoCommand = new GetInfoCommand(plant);
        setCommand(getInfoCommand);
        command->execute();
		result.first = getInfoCommand->getInfo();
		return result;
	}
	else if(next){
		return next->handleRequest(requestType, plant, order, flags);
	} 
	result.first = "No staff could handle the request: '" + requestType + "'\n";
	return result;
}

string NurseryStaff::getPosition() {
	return "Nursery staff";
}

void NurseryStaff::update(const string& message) {
	cout << getName() << " (" << getPosition() << ") received observer update: " << message << endl;
}