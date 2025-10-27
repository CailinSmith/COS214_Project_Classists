/**
 * @file Cattails.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef CATTAILS_H
#define CATTAILS_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "Reduction.h"

class Cattails : public Aquatic {
	
public:
	Cattails() : Aquatic(300, new HighMoisture(), new Reduction(), "Cattails", "Summer") {}
};

#endif
