/**
 * @file MediumMoisture.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

 #ifndef MEDIUMMOISTURE_H
#define MEDIUMMOISTURE_H

#include "WateringStrategy.h"
#include <string>
#include <iostream>
using namespace std;

class MediumMoisture : public WateringStrategy {
public:
	void water(Plant* plant);
	string print();
};

#endif
