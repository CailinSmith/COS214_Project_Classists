#ifndef ALOEVERA_H
#define ALOEVERA_H

#include "Medicinal.h"
#include "DryPlant.h"
#include "Thinning.h"

class AloeVera : public Medicinal {
public:
	AloeVera() : Medicinal(60, new DryPlant(), new Thinning(), "Aloe Vera") {}
};

#endif
