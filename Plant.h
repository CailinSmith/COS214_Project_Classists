#ifndef PLANT_H
#define PLANT_H

#include "Product.h"
#include <string>

class WateringStrategy;  // Forward declarations
class PruningStrategy;
class PlantState;
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

public:
	Plant();

	void water();

	void prune();

	string summary();

	float getWaterLevel();

	void setWaterLevel(float level);

	bool getPruned();

	void setPruned();

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
};

#endif
