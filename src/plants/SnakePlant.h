#ifndef SNAKEPLANT_H
#define SNAKEPLANT_H

#include "Indoor.h"
#include "DryPlant.h"
#include "NoPrune.h"

class SnakePlant : public Indoor {
public:
	SnakePlant() : Indoor(120, new DryPlant(), new NoPrune(), "SnakePlant") {}
};

#endif
