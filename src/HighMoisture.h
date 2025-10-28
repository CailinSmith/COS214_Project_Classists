/**
 * @file HighMoisture.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef HIGHMOISTURE_H
#define HIGHMOISTURE_H

#include "WateringStrategy.h"
#include "Plant.h"
#include <string>
#include <iostream>
using namespace std;

class HighMoisture : public WateringStrategy {
public:
	void water(Plant* plant);
	string print();
};

#endif
