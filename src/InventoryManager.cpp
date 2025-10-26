#include "InventoryManager.h"
#include "NurseryStaff.h"
#include "Manager.h"

Iterator<Plant>* InventoryManager::createIterator(const std::string& season) {
	std::vector<Plant*> allPlants;
	allPlants.insert(allPlants.end(), forSale.begin(), forSale.end());
	allPlants.insert(allPlants.end(), inNursery.begin(), inNursery.end());
	return new SeasonIterator(allPlants, season);
}

Iterator<Plant>* InventoryManager::createSaleIterator(const std::string& season) {
	return new SeasonIterator(forSale, season);
}

Iterator<Plant>* InventoryManager::createNurseryIterator(const std::string& season) {
	return new SeasonIterator(inNursery, season);
}

int catNumber(string category){
    if (category == "Flower") return 0;
    if (category == "Herb") return 1;
    if (category == "Fruit") return 2;
    if (category == "Vegetable") return 3;
    if (category == "Succulent") return 4;
    if (category == "Aquatic") return 5;
    if (category == "Indoor") return 6;
    if (category == "Medicinal") return 7;
	return -1;
}


void InventoryManager::addToSale(Plant* plant) {
	if(!plant)
	{
		return;
	}

	size_t i = 0;
	while (i < forSale.size()) {
		int plantCat = catNumber(plant->getCategory());
		int currentCat = catNumber(forSale[i]->getCategory());
		
		if (plantCat < currentCat) break;
		else if (plantCat == currentCat && plant->getName() < forSale[i]->getName()) break;
		i++;
	}

	forSale.insert(forSale.begin() + i, plant);
	std::cout << "Added " << plant->getName() << " to sale." << std::endl;
	checkAndNotify();
}

void InventoryManager::addToNursery(Plant* plant) {
	if(!plant)
	{
		return;
	}

	size_t i = 0;
	while (i < inNursery.size()) {
		int plantCat = catNumber(plant->getCategory());
		int currentCat = catNumber(inNursery[i]->getCategory());
		
		if (plantCat < currentCat) break;
		else if (plantCat == currentCat && plant->getName() < inNursery[i]->getName()) break;
		i++;
	}
	inNursery.insert(inNursery.begin() + i, plant);
	std::cout << "Added " << plant->getName() << " to nursery." << std::endl;
	checkAndNotify();
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
			checkAndNotify();
			return;
		}
	}
	
	std::cout << plant->getName() << " not found in sale." << std::endl;
}

void InventoryManager::notifyStaff(string message) {
    cout << "Notifying all observers: " << message << endl;
    for(size_t i = 0; i < observerList.size(); i++)
	{
        if(observerList[i] != nullptr)
		{
            NurseryStaff* nurseryStaff = dynamic_cast<NurseryStaff*>(observerList[i]);
            if(nurseryStaff)
			{
                nurseryStaff->update(message);
                continue;
            }
            
            Manager* manager = dynamic_cast<Manager*>(observerList[i]);
            if(manager)
			{
                manager->update(message);
                continue;
            }
            
            observerList[i]->receive(message);
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
    
    for(size_t i = 0; i < forSale.size(); i++)
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

    for(size_t i = 0; i < inNursery.size(); i++)
	{
        if(inNursery[i] == plant)
		{
            return true;
        }
    }
    return false;
}

void InventoryManager::registerObserver(Staff* staff) {
	if(staff == nullptr)
	{
		return;
	}
	observerList.push_back(staff);
}

void InventoryManager::deregisterObserver(Staff* staff) {
	if(staff == nullptr)
	{
		return;
	} 
	observerList.erase(std::remove(observerList.begin(), observerList.end(), staff), observerList.end());
}

void InventoryManager::checkAndNotify() {
	if(forSale.size() < saleThreshold)
	{
		notifyStaff("Low stock: forSale count below threshold");
	}
	
	if(inNursery.size() < nurseryThreshold)
	{
		notifyStaff("Low stock: nursery count below threshold");
	}
}
