/**
 * @file WaterHyacinth.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef WATERHYACINTH_H
#define WATERHYACINTH_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "Thinning.h"

class WaterHyacinth : public Aquatic {

public:
	WaterHyacinth() : Aquatic(30, new HighMoisture(), new Thinning(), "Water Hyacinth") {}
};

#endif
