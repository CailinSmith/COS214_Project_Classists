#include "Plant.h"
#include <iomanip>
#include <sstream>

Plant::Plant(string category, int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name) {
	this->category = category;
	this->maxHeight = maxHeight;
	this->wateringStrat = wateringStrat;
	this->pruningStrat = pruningStrat;
	this->waterLevel = 0.0;
	this->health = 0.0;
	this->height = 0.0;
	this->currentState = new SeedState();
	this->pruned = false; //made false for testing purposes, change to true once state is implemented
	this->sold = false;
	this->totalWater = 0;
	this->name = name;
	this->cost = 0.0; //ook testing purposes
	this->sellSeaon = "Summer"; //also testing purposes 
}

Plant::~Plant() {
	delete wateringStrat;
	delete pruningStrat;
	delete currentState;
}

void Plant::water() {
	this->wateringStrat->water(this);
}

void Plant::prune() {
	this->pruningStrat->prune(this);
}

void Plant::fertilise() {
	this->health += 0.3; 
	if (this->health > 1) {
		this->health = 1; 
	}
	std::cout << this->name << " has been fertilised. Health is now " << this->health << "." << std::endl;
}

string Plant::summary() {
	stringstream ss;
	string out = "";
	out += "Plant Name: " + this->name + "\n";
	out += "Category: " + this->category + "\n";
	
	ss << fixed << setprecision(2) << this->getActualHeight();
	out += "Height: " + ss.str() + " cm\n";
	ss.str(""); ss.clear();
	
	ss << fixed << setprecision(2) << this->health;
	out += "Health: " + ss.str() + "\n";
	ss.str(""); ss.clear();
	
	ss << fixed << setprecision(2) << this->waterLevel;
	out += "Water Level: " + ss.str() + "\n";
	ss.str(""); ss.clear();
	
	out += "Pruned: " + string(this->pruned ? "Yes" : "No") + "\n";
	out += "State: " + this->currentState->print() + "\n";
	out += "Total Water Given: " + to_string(this->totalWater) + " ml\n";
	out += "Max Height: " + to_string(this->maxHeight) + " cm\n";
	out += "Watering Strategy: " + this->wateringStrat->print() + "\n";
	out += "Pruning Strategy: " + this->pruningStrat->print() + "\n";
	out += "Sell Season: " + this->sellSeaon + "\n";
	
	ss << fixed << setprecision(2) << this->cost;
	out += "Cost: " + ss.str() + "\n";
	
	return out;
}

string Plant::customerSummary() {
	stringstream ss;
	string out = "";
	out += "Plant Name: " + this->name + "\n";
	out += "Category: " + this->category + "\n";
	
	ss << fixed << setprecision(2) << this->getActualHeight();
	out += "Height: " + ss.str() + " cm\n";
	ss.str(""); ss.clear();
	
	ss << fixed << setprecision(2) << this->health;
	out += "Health: " + ss.str() + "\n";
	ss.str(""); ss.clear();
	
	out += "State: " + this->currentState->print() + "\n";
	
	ss << fixed << setprecision(2) << this->cost;
	out += "Cost: " + ss.str() + "\n";
	
	return out;
}

float Plant::getWaterLevel() {
	return this->waterLevel;
}

void Plant::setWaterLevel(float level) {
	this->waterLevel = level;
}

bool Plant::getPruned() {
	return this->pruned;
}

void Plant::setPruned(bool pruned) {
	this->pruned = pruned;
}

string Plant::getCategory() {
	return this->category;
}

float Plant::getHeight() {
	return this->height;
}

void Plant::setHeight(float height) {
	this->height = height;
}

float Plant::getActualHeight() {
	return this->height * this->maxHeight;
}

string Plant::getState() {
	return this->currentState->print();
}

void Plant::setState(PlantState* state) {
	if (currentState) 
		delete currentState;
	currentState = state;
}

void Plant::setHealth(float health) {
	this->health = health;
}

float Plant::getHealth() {
	return this->health;
}

void Plant::setSold(bool sold) {
	this->sold = sold;
}

void Plant::setTotalWater(int total) {
	this->totalWater = total;
}

int Plant::getTotalWater() {
	return this->totalWater;
}

int Plant::getMaxHeight() {
	return this->maxHeight;
}

string Plant::getStrategies() {
	string out = "";
	out += this->wateringStrat->print() + ", " + this->pruningStrat->print();
	return out;
}

string Plant::getName() {
	return this->name;
}

void Plant::changePlantState() {
    currentState->change(this);
}

string Plant::getSellSeason() {
	return sellSeaon;
}

float Plant::seasonCost(string curSeason) {
	return 0;
}

float Plant::calculateCost(string currSeason) {
	float ncost =baseCost();
	if (getHealth() >0.9)
		ncost += baseCost()*(getHealth()-0.85);
	ncost += seasonCost(currSeason);
	cost=ncost;
	return ncost;
}

float Plant::getCost() {
	return cost;
}