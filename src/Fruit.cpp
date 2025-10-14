#include "Fruit.h"

float Fruit::baseCost() {
    return 200.0;
}

float Fruit::seasonCost(string curSeason) {
    if (getSellSeason() == curSeason ) 
        return baseCost() * 0.15; 
    return 0;
}