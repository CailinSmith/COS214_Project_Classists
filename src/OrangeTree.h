/**
 * @file OrangeTree.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef ORANGETREE_H
#define ORANGETREE_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class OrangeTree : public Fruit {
public:
	OrangeTree() : Fruit(600, new MediumMoisture(), new Thinning(), "Orange Tree", "Winter") {}
};

#endif
