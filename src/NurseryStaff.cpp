#include "NurseryStaff.h"
#include "Customer.h"

NurseryStaff::NurseryStaff(string name) : Staff(name){}

std::string NurseryStaff::handleRequest(Customer* customer, const std::string& requestType, Plant* plant, std::vector<Product*>* order) {
	// TODO - implement NurseryStaff::handleRequest
	cout << getName() << " (" << getPosition() << ") handling mediator request." << endl;
	std::cout << "Nursery staff: " << name << " handled request.\n";
	if(requestType == "CheckStock" && plant){ // code below leaks due to Nursery, InventoryManager and StaffCheckStockCommand each having leaks
		InventoryManager* inventoryManager = new InventoryManager();
		Nursery* nursery = Nursery::getInstance(inventoryManager);
		InventoryManager* im = nursery->getInventoryManager();
		StaffCheckStockCommand cmd(plant, im);
		cmd.execute();
		int stock = cmd.getStock();
		delete inventoryManager;
		return stock + " units of " + plant->getName() + " are in stock.\n";
	}
	else if(requestType == "AskInfo" && plant){
		GetInfoCommand cmd(plant);
		cmd.execute(); // 1 leak from here
		return cmd.getInfo();
	}
	else if(next){
		return next->handleRequest(customer, requestType, plant, order);
	}
	return "No staff could handle the request: '" + requestType + "'\n";
}

string NurseryStaff::getPosition() {
	return "Nursery staff";
}

void NurseryStaff::update(const string& message) {
	cout << getName() << " (" << getPosition() << ") received observer update: " << message << endl;
}