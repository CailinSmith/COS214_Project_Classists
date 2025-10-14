/**
 * @file Plant.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef PLANT_H
#define PLANT_H

#include "Product.h"
#include "WateringStrategy.h"
#include "PruningStrategy.h"
#include "PlantState.h"
#include "SeedState.h"
#include <string>
#include <iostream>

using namespace std;

class Plant : public Product {
private:
	WateringStrategy* wateringStrat;
	PruningStrategy* pruningStrat;  
	float waterLevel;
	float health;
	float height;
	PlantState* currentState;
	int maxHeight;
	bool pruned;  
	bool sold;
	string category;
	int totalWater;
	string name;

public:
	Plant(string category, int maxHeight, WateringStrategy* waterStrat, PruningStrategy* pruneStrat, string name);
	
	virtual ~Plant();

	void water();

	void prune();

	void fertilise();

	string summary();

	float getWaterLevel();

	void setWaterLevel(float level);

	bool getPruned();

	void setPruned(bool pruned);

	string getCategory();

	float getHeight();

	void setHeight(float height);

	float getActualHeight();

	string getState();

	void setState(PlantState* state);

	void setHealth(float health);

	float getHealth();

	void setSold(bool sold);

	void setTotalWater(int total);

	int getTotalWater();

	int getMaxHeight();

	string getStrategies();

	string getName();
};

#endif
