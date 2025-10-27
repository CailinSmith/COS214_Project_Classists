#ifndef NURSERY_H
#define NURSERY_H

#include "SeasonState.h"
#include "PlantFactory.h"
#include "InventoryManager.h"
#include "Staff.h"
#include <string>
using namespace std;

// Forward declarations
class Spring;
class SpringFactory;

class Nursery {
	/*how to use:
	first initialize:
	InventoryManager* inventoryManager = new InventoryManager();
	Nursery* nursery = Nursery::getInstance(inventoryManager);

	to access inventorymanager:
	InventoryManager* im = nursery->getInventoryManager();

	to access the singleton:
	Nursery* n = Nursery::getInstance();
	*/

private:
	static Nursery* instance;
	InventoryManager* inventoryManager;
	SeasonState* currentSeason;
	PlantFactory* currentFactory;
protected:
	Nursery(InventoryManager* manager);
	Nursery(const Nursery&) = delete;
	Nursery& operator=(const Nursery&) = delete;
	~Nursery();

public:

	static Nursery* getInstance(InventoryManager* manager = nullptr);	
	// Destroy the singleton instance (safe to call at program/test teardown)
	static void destroyInstance();

	InventoryManager* getInventoryManager();
	//clear the pointer to the inventory manager (used when the manager is destroyed)
	void clearInventoryManager();
	
	void setSeason(SeasonState* season);

	string getSeason();

	void setFactory(PlantFactory* factory);

	//called by client to change the season --> calls change on currentSeason
	void changeSeason();

	void stockNursery();
};

#endif