#ifndef NURSERY_H
#define NURSERY_H

#include "SeasonState.h"
#include "PlantFactory.h"
#include <string>
using namespace std;

class Nursery {

private:
	SeasonState* currentSeason;
	PlantFactory* currentFactory;

public:
	/**
	 * Changes currentSeason and currentFactory variable
	 */
	void setSeason(SeasonState* season);

	string getSeason();

	void setFactory(PlantFactory* factory);

	void changeSeason();

	void stockNursery();
};

#endif
