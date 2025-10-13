/**
 * @file Pumpkin.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef PUMPKIN_H
#define PUMPKIN_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "Thinning.h"

class Pumpkin : public Vegetable {
public:
	Pumpkin() : Vegetable(60, new HighMoisture(), new Thinning(), "Pumpkin") {}
};

#endif
