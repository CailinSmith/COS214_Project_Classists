/**
 * @file Tomato.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef TOMATO_H
#define TOMATO_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class Tomato : public Fruit {

public:
	Tomato() : Fruit(150, new MediumMoisture(), new Thinning(), "Tomato") {}
};

#endif
