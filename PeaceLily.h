#ifndef PEACELILY_H
#define PEACELILY_H

#include "Indoor.h"
#include "HighMoisture.h"
#include "DeadPruning.h"

class PeaceLily : public Indoor {

public:
	PeaceLily() : Indoor(120, new HighMoisture(), new DeadPruning(), "Peace Lily") {}
};

#endif
