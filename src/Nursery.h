#ifndef NURSERY_H
#define NURSERY_H

#include "SeasonState.h"
#include "PlantFactory.h"
#include "InventoryManager.h"
#include <string>
using namespace std;

// Forward declarations
class Spring;
class SpringFactory;

class Nursery {

private:
	InventoryManager* inventoryManager;
	SeasonState* currentSeason;
	PlantFactory* currentFactory;

public:
	Nursery(InventoryManager* manager);

	~Nursery();
	
	void setSeason(SeasonState* season);

	string getSeason();

	void setFactory(PlantFactory* factory);

	//called by client to change the season --> calls change on currentSeason
	void changeSeason();

	void stockNursery();
};

#endif
