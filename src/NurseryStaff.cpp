#include "NurseryStaff.h"
#include "Customer.h"

NurseryStaff::NurseryStaff(string name) : Staff(name){}

pair<string, Receipt*> NurseryStaff::handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) {
	// TODO - implement NurseryStaff::handleRequest
	pair<string, Receipt*> result;
	result.second = nullptr;

	if(requestType == "CheckStock" && plant){
		InventoryManager* inventoryManager = new InventoryManager();
		Nursery* nursery = Nursery::getInstance(inventoryManager);
		InventoryManager* im = nursery->getInventoryManager();
		StaffCheckStockCommand cmd(plant, im);
		cmd.execute();
		int stock = cmd.getStock();
		delete inventoryManager;
		result.first = to_string(stock) + " units of " + plant->getName() + " are in stock.\n";
		return result;
	}
	else if(requestType == "AskInfo" && plant){
		GetInfoCommand cmd(plant);
		cmd.execute();
		result.first = cmd.getInfo();
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