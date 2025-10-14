#include "Flower.h"

float Flower::baseCost() {
	return 100.0;
}

float Flower::seasonCost(string curSeason) {
	if (getSellSeason() == curSeason ) 
		return baseCost() * 0.1; 
	return 0;
}
