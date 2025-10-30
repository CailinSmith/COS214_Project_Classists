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
#include "SeedState.h"
#include <string>
#include <iostream>

using namespace std;

// Forward declaration to break circular include
class PlantState;

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
	float cost;
	string sellSeason;

public:
	Plant(string category, int maxHeight, WateringStrategy* waterStrat, PruningStrategy* pruneStrat, string name, string sellSeason);

	virtual ~Plant();

	void water();

	void prune();

	void fertilise();

	string summary();

	string customerSummary();

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

    void changePlantState();

	void changeHealth();

	string getSellSeason();

	float calculateCost(string currSeason);
	virtual float baseCost() = 0;
	virtual float seasonCost(string curSeason);
	float getCost();

	virtual Plant* getBasePlant() {
		return this;
	}
};

#endif