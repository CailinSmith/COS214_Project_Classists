/**
 * @file Pothos.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef POTHOS_H
#define POTHOS_H

#include "Indoor.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class Pothos : public Indoor {

public:
	Pothos() : Indoor(300, new MediumMoisture(), new Thinning(), "Pothos", "Winter") {}
};

#endif
