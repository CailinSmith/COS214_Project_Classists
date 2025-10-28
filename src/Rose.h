/**
 * @file Rose.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef ROSE_H
#define ROSE_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

class Rose : public Flower {
public:
	Rose() : Flower(180, new MediumMoisture(), new DeadPruning(), "Rose", "Spring") {}
};

#endif
