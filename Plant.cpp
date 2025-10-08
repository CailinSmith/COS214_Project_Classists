#include "Plant.h"

Plant::Plant() {
	// TODO - implement Plant::Plant
	throw "Not yet implemented";
}

void Plant::water() {
	// TODO - implement Plant::water
	throw "Not yet implemented";
}

void Plant::prune() {
	// TODO - implement Plant::prune
	throw "Not yet implemented";
}

string Plant::summary() {
	// TODO - implement Plant::summary
	throw "Not yet implemented";
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

void Plant::setPruned() {
	// TODO - implement Plant::setPruned
	throw "Not yet implemented";
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
	// TODO - implement Plant::getActualHeight
	throw "Not yet implemented";
}

string Plant::getState() {
	// TODO - implement Plant::getState
	throw "Not yet implemented";
}

void Plant::setState(PlantState* state) {
	// TODO - implement Plant::setState
	throw "Not yet implemented";
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
	// TODO - implement Plant::getStrategies
	throw "Not yet implemented";
}
