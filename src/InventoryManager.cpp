#include "InventoryManager.h"


void InventoryManager::addToSale(Plant* plant) {
	if(!plant)
	{
		return;
	}
	forSale.push_back(plant);
	std::cout << "Added " << plant->getName() << " to sale." << std::endl;
}

void InventoryManager::addToNursery(Plant* plant) {
	if(!plant)
	{
		return;
	}
	inNursery.push_back(plant);
	std::cout << "Added " << plant->getName() << " to nursery." << std::endl;
}

void InventoryManager::removeFromNursery(Plant* plant) {
	if(plant == nullptr)
	{
		std::cout << "Cannot remove null plant from nursery." << std::endl;
		return;
	}
	
	for(size_t i = 0; i < inNursery.size(); i++)
	{
		if(inNursery[i] == plant)
		{
			inNursery.erase(inNursery.begin() + i);
			std::cout << "Removed " << plant->getName() << " from nursery." << std::endl;
			return;
		}
	}
	
	std::cout << plant->getName() << " not found in nursery." << std::endl;
}

void InventoryManager::removeFromSale(Plant* plant) {
	if(plant == nullptr)
	{
		std::cout << "Cannot remove null plant from sale." << std::endl;
		return;
	}
	
	for(size_t i = 0; i < forSale.size(); i++)
	{
		if(forSale[i] == plant)
		{
			forSale.erase(forSale.begin() + i);
			std::cout << "Removed " << plant->getName() << " from sale." << std::endl;
			return;
		}
	}
	
	std::cout << plant->getName() << " not found in sale." << std::endl;
}

void InventoryManager::notifyStaff(string message) {
    cout << "Notifying all staff: " << message << endl;
    for(int i = 0; i < observerList.size(); i++)
	{
        if(observerList[i] != nullptr)
		{
            // observerList[i]->update(message);
            cout << "Staff member notified" << endl;
        }
    }
}

size_t InventoryManager::getSaleCount() const {
    return forSale.size();
}

size_t InventoryManager::getNurseryCount() const {
    return inNursery.size();
}

bool InventoryManager::isInSale(Plant* plant) const {
    if(plant == nullptr)
	{
		return false;
	}
    
    for(int i = 0; i < forSale.size(); i++)
	{
        if(forSale[i] == plant)
		{
            return true;
        }
    }
    return false;
}

bool InventoryManager::isInNursery(Plant* plant) const {
    if(plant == nullptr)
	{
		return false;
	}

    for(int i = 0; i < inNursery.size(); i++)
	{
        if(inNursery[i] == plant)
		{
            return true;
        }
    }
    return false;
}
