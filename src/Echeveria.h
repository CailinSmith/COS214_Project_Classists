/**
 * @file Echeveria.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef ECHEVERIA_H
#define ECHEVERIA_H

#include "Succulent.h"
#include "DryPlant.h"
#include "Thinning.h"

class Echeveria : public Succulent {

public:
	Echeveria() : Succulent(30, new DryPlant(), new Thinning(), "Echeveria", "Summer") {}
};

#endif
