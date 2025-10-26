/**
 * @file Kale.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef KALE_H
#define KALE_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "NoPrune.h"

class Kale : public Vegetable {

public:
	Kale() : Vegetable(60, new HighMoisture(), new NoPrune(), "Kale", "Autumn") {}
};

#endif
