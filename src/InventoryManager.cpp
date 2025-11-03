#include "InventoryManager.h"
#include "NurseryStaff.h"
#include "Manager.h"
// include Nursery here so destructor can clear nursery pointer when manager is destroyed
#include "Nursery.h"

// demo helpers: factory pattern
#include "SpringFactory.h"
#include "SummerFactory.h"
#include "AutumnFactory.h"
#include "WinterFactory.h"
#include "ReadyForSaleState.h"

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
	SpringFactory springFactory;
	SummerFactory summerFactory;
	AutumnFactory autumnFactory;
	WinterFactory winterFactory;
	PlantFactory* factories[] = {&springFactory, &summerFactory, &autumnFactory, &winterFactory};
	int numFactories = 4;
	
	enum PlantType { FLOWER, HERB, FRUIT, VEGETABLE, SUCCULENT, AQUATIC, INDOOR, MEDICINAL };
	int numTypes = 8;
	
	for (size_t i = 0; i < saleCount; ++i) {
		PlantFactory* factory = factories[i % numFactories];
		PlantType type = static_cast<PlantType>(i % numTypes);
		
		Plant* p = nullptr;
		switch (type) {
			case FLOWER:
				p = factory->createFlower();
				break;
			case HERB:
				p = factory->createHerb();
				break;
			case FRUIT:
				p = factory->createFruit();
				break;
			case VEGETABLE:
				p = factory->createVegetable();
				break;
			case SUCCULENT:
				p = factory->createSucculent();
				break;
			case AQUATIC:
				p = factory->createAquatic();
				break;
			case INDOOR:
				p = factory->createIndoor();
				break;
			case MEDICINAL:
				p = factory->createMedicinal();
				break;
		}
		
		if (p) {
			p->setHealth(0.9);
			p->calculateCost("Spring");
			p->setHeight(0.9);
			p->setState(new ReadyForSaleState());
			addToSale(p);
		}
	}

	for (size_t i = 0; i < nurseryCount; ++i) {
		PlantFactory* factory = factories[(i + 2) % numFactories];
		PlantType type = static_cast<PlantType>((i + 4) % numTypes);
		
		Plant* p = nullptr;
		switch (type) {
			case FLOWER:
				p = factory->createFlower();
				break;
			case HERB:
				p = factory->createHerb();
				break;
			case FRUIT:
				p = factory->createFruit();
				break;
			case VEGETABLE:
				p = factory->createVegetable();
				break;
			case SUCCULENT:
				p = factory->createSucculent();
				break;
			case AQUATIC:
				p = factory->createAquatic();
				break;
			case INDOOR:
				p = factory->createIndoor();
				break;
			case MEDICINAL:
				p = factory->createMedicinal();
				break;
		}
		
		if (p) {
			addToNursery(p);
		}
	}
}

InventoryManager::~InventoryManager() {
	//if this manager was registered with the Nursery singleton, clear that pointer
	Nursery* nursery = Nursery::getInstance();
	if (nursery != nullptr && nursery->getInventoryManager() == this) {
		nursery->clearInventoryManager();
	}

	for (size_t i = 0; i < forSale.size(); ++i) {
		delete forSale[i];
	}
	for (size_t i = 0; i < inNursery.size(); ++i) {
		delete inNursery[i];
	}
	
	forSale.clear();
	inNursery.clear();
	observerList.clear();
}
