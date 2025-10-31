#include "InventoryManager.h"
#include "NurseryStaff.h"
#include "Manager.h"
// include Nursery here so destructor can clear nursery pointer when manager is destroyed
#include "Nursery.h"

// demo helpers: plant types and strategies
#include "Rose.h"
#include "Basil.h"
#include "AloeVera.h"
#include "Cattails.h"
#include "Pothos.h"
#include "Chamomile.h"
#include "Pansy.h"
#include "Kale.h"
#include "Echeveria.h"
#include "OrangeTree.h"
#include "Cucumber.h"
#include "PeaceLily.h"

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


void InventoryManager::addToSale(Plant* plant) {
	if(!plant)
	{
		return;
	}

	size_t i = 0;
	while (i < forSale.size()) {
		int plantCat = priority[plant->getCategory()];
		int currentCat = priority[forSale[i]->getCategory()];
		if (plantCat < currentCat) break;
		else if (plantCat == currentCat && plant->getName() < forSale[i]->getName()) break;
		i++;
	}

	forSale.insert(forSale.begin() + i, plant);
	checkAndNotify();
}

void InventoryManager::addToNursery(Plant* plant) {
	if(!plant)
	{
		return;
	}

	size_t i = 0;
	while (i < inNursery.size()) {
		int plantCat = priority[plant->getCategory()];
		int currentCat = priority[inNursery[i]->getCategory()];

		if (plantCat < currentCat) break;
		else if (plantCat == currentCat && plant->getName() < inNursery[i]->getName()) break;
		i++;
	}
	inNursery.insert(inNursery.begin() + i, plant);
	checkAndNotify();
}

void InventoryManager::removeFromNursery(Plant* plant) {
	if(plant == nullptr)
	{
		return;
	}
	
	for(size_t i = 0; i < inNursery.size(); i++)
	{
		if(inNursery[i] == plant)
		{
			inNursery.erase(inNursery.begin() + i);
			return;
		}
	}
	
}

void InventoryManager::removeFromSale(Plant* plant) {
	if(plant == nullptr)
	{
		return;
	}
	
	for(size_t i = 0; i < forSale.size(); i++)
	{
		if(forSale[i] == plant)
		{
			forSale.erase(forSale.begin() + i);
			checkAndNotify();
			return;
		}
	}
	
}

void InventoryManager::notifyStaff(string message) {
    for(size_t i = 0; i < observerList.size(); i++)
	{
        if(observerList[i] != nullptr && (observerList[i]->getPosition() == "Nursery staff" || observerList[i]->getPosition() == "Manager"))
		{
            observerList[i]->update(message);
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

void InventoryManager::populateDemoInventory(size_t nurseryCount, size_t saleCount) {
	// Create a small variety of plants for sale
	for (size_t i = 0; i < saleCount; ++i) {
		Plant* p = nullptr;
		switch (i % 6) {
			case 0:
				p = new Rose();
				break;
			case 1:
				p = new Basil();
				break;
			case 2:
				p = new AloeVera();
				break;
			case 3:
				p = new Cattails();
				break;
			case 4:
				p = new Pothos();
				break;
			case 5:
				p = new Chamomile();
				break;
		}
		if (p) {
			p->setHealth(0.9);
			p->setHealth(0.9);
			p->calculateCost("Spring");
			p->setState(new ReadyForSaleState());
			addToSale(p);
		}
	}

	// Create nursery plants
	for (size_t i = 0; i < nurseryCount; ++i) {
		Plant* p = nullptr;
		switch (i % 6) {
			case 0:
				p = new Pansy();
				break;
			case 1:
				p = new Kale();
				break;
			case 2:
				p = new Echeveria();
				break;
			case 3:
				p = new OrangeTree();
				break;
			case 4:
				p = new Cucumber();
				break;
			case 5:
				p = new PeaceLily();
				break;
		}
		if (p) addToNursery(p);
	}
}

InventoryManager::~InventoryManager() {
	//if this manager was registered with the Nursery singleton, clear that pointer
	Nursery* nursery = Nursery::getInstance();
	if (nursery != nullptr && nursery->getInventoryManager() == this) {
		nursery->clearInventoryManager();
	}

	//dont delete plants, just clear vectors
	forSale.clear();
	inNursery.clear();
	observerList.clear();
}
