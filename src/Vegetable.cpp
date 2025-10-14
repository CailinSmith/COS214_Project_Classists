#include "Vegetable.h"

float Vegetable::baseCost() {
    return 80.0;
}

float Vegetable::seasonCost(string curSeason) {
    if (getSellSeason() == curSeason ) 
        return baseCost() * 0.15; 
    return 0;
}