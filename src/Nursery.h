#ifndef NURSERY_H
#define NURSERY_H

#include "SeasonState.h"
#include "PlantFactory.h"
#include "InventoryManager.h"
#include <string>
using namespace std;

#include "SpringFactory.h"
#include "Spring.h"

class Nursery {

private:
	InventoryManager* inventoryManager;
	SeasonState* currentSeason;
	PlantFactory* currentFactory;

public:
	/**
	 * Changes currentSeason and currentFactory variable
	 */
	Nursery(InventoryManager* manager) : inventoryManager(manager) {
		//temporary to test command
		currentSeason = new Spring();
		currentFactory = new SpringFactory();
	}
	void setSeason(SeasonState* season);

	string getSeason();

	void setFactory(PlantFactory* factory);

	//called by client to change the season --> calls change on currentSeason
	void changeSeason();

	void stockNursery();
};

#endif
