/**
 * @file DryPlant.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef DRYPLANT_H
#define DRYPLANT_H

#include "WateringStrategy.h"
#include "Plant.h"
#include <string>
#include <iostream>
using namespace std;

class DryPlant : public WateringStrategy {
public:
	void water(Plant* plant);
	string print();
};

#endif
