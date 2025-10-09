#ifndef CHAMOMILE_H
#define CHAMOMILE_H

#include "Medicinal.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class Chamomile : public Medicinal {

public:
	Chamomile() : Medicinal(60, new MediumMoisture(), new Thinning(), "Chamomile") {}
};

#endif
