#include "Plant.h"

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
	string out = "";
	out += "Plant Name: " + this->name + "\n";
	out += "Category: " + this->category + "\n";
	out += "Height: " + to_string(this->getActualHeight()) + " cm\n";
	out += "Health: " + to_string(this->health) + "\n";
	out += "Water Level: " + to_string(this->waterLevel) + "\n";
	out += "Pruned: " + string(this->pruned ? "Yes" : "No") + "\n";
	out += "State: " + this->currentState->print() + "\n";
	out += "Total Water Given: " + to_string(this->totalWater) + " ml\n";
	out += "Max Height: " + to_string(this->maxHeight) + " cm\n";
	out += "Watering Strategy: " + this->wateringStrat->print() + "\n";
	out += "Pruning Strategy: " + this->pruningStrat->print() + "\n";
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